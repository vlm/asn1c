#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <UserIdentifier.h>

static unsigned char buf[4096];
static int buf_offset;

static int
_buf_writer(const void *buffer, size_t size, void *app_key) {
	unsigned char *b, *bend;
	(void)app_key;
	assert(buf_offset + size < sizeof(buf));
	memcpy(buf + buf_offset, buffer, size);
	b = buf + buf_offset;
	bend = b + size;
	printf("=> [");
	for(; b < bend; b++)
		printf(" %02X", *b);
	printf("]:%zd\n", size);
	buf_offset += size;
	return 0;
}

static int
save_object(void *bs, asn_TYPE_descriptor_t *td) {
	asn_enc_rval_t rval; /* Return value */
	int i;
	
	rval = der_encode(td, bs, _buf_writer, 0);
	if (rval.encoded == -1) {
		fprintf(stderr,
			"Cannot encode %s: %s\n",
			rval.failed_type->name, strerror(errno));
		assert(rval.encoded != -1);
		return -1;	/* JIC */
	}

	buf[buf_offset++] = 123;	/* Finalize with garbage */

	asn_fprint(stderr, td, bs);
	xer_fprint(stderr, td, bs);

	printf("OUT: [");
	for(i = 0; i < buf_offset; i++)
		printf(" %02x", buf[i]);
	printf("]\n");

	return 0;
}

static int
load_object(void *bs, asn_TYPE_descriptor_t *td) {
	asn_dec_rval_t rval;

	fprintf(stderr, "\nLOADING OBJECT OF SIZE %d\n", buf_offset);

	rval = ber_decode(0, td, (void **)&bs, buf, buf_offset);
	assert(rval.code == RC_OK);

	asn_fprint(stderr, td, bs);
	xer_fprint(stderr, td, bs);

	return (rval.code == RC_OK)?0:-1;
}

int
main() {
	asn_TYPE_descriptor_t *td = &asn_DEF_UserIdentifier;
	UserIdentifier_t user;
	UserIdentifier_t user_new;
	int ret;

	memset(&user, 0, sizeof user);
	memset(&user_new, 0, sizeof user_new);

	user.present = UserIdentifier_PR_phoneNumber;
	OCTET_STRING_fromBuf(
		&user.choice.phoneNumber,
		"0123456789", -1);

	/* Save->Load must succeed */
	save_object(&user, td);
	ret = load_object(&user_new, td);

	assert(user_new.present == UserIdentifier_PR_phoneNumber);

	assert(ret == 0);

	printf("OK\n");

	ASN_STRUCT_RESET(asn_DEF_UserIdentifier, &user);
	ASN_STRUCT_RESET(asn_DEF_UserIdentifier, &user_new);
	return ret;
}
