#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include "T.h"
#include "per_opentype.h"

int
main() {
	asn_per_data_t pd;
	asn_per_outp_t po;
	asn_dec_rval_t rv;
	T_t t;
	T_t *t2 = 0;
	size_t i;

	memset(&po, 0, sizeof po);
	po.buffer = po.tmpspace;
	po.nbits = sizeof(po.tmpspace) * 8;

	memset(&t, 0, sizeof t);

	printf("Checking uper_open_type_put():\n");
	assert(0 == uper_open_type_put(&asn_DEF_T, 0, &t, &po));
	assert(po.nbits == (-1 + (int)sizeof(po.tmpspace)) * 8);
	printf("po{nboff=%zd; nbits=%zd; buffer=%p; tmpspace=%p}\n",
		po.nboff, po.nbits, po.buffer, po.tmpspace);
	/* One byte length and one byte 0x00 */
	assert(    (po.nboff == 8 && po.buffer == &po.tmpspace[1])
		|| (po.nboff == 0 && po.buffer == &po.tmpspace[2]));
	assert(po.tmpspace[0] == 0x01);
	assert(po.tmpspace[1] == 0x00);

	printf("\nChecking uper_open_type_get():\n");
	for(i = 0; i < 16; i++) {
		FREEMEM(t2); t2 = 0;
		memset(&pd, 0, sizeof pd);
		pd.buffer = po.tmpspace;
		pd.nboff = 0;
		pd.nbits = i;
		rv = uper_open_type_get(0, &asn_DEF_T, 0, (void **)&t2, &pd);
		assert(rv.code == RC_WMORE);
	}

	memset(&pd, 0, sizeof pd);
	pd.buffer = po.tmpspace;
	pd.nboff = 0;
	pd.nbits = 16;
	rv = uper_open_type_get(0, &asn_DEF_T, 0, (void **)&t2, &pd);
	assert(rv.code == RC_OK);
	assert(    (pd.nboff == 8 && pd.buffer == &po.tmpspace[1])
		|| (pd.nboff == 16 && pd.buffer == &po.tmpspace[0]));
	assert(pd.nboff + pd.nbits == 16);

	ASN_STRUCT_FREE(asn_DEF_T, t2);
	return 0;
}
