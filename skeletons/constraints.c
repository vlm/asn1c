#include <asn_internal.h>
#include <constraints.h>

int
asn_generic_no_constraint(asn_TYPE_descriptor_t *type_descriptor,
	const void *struct_ptr, asn_app_consume_bytes_f *cb, void *key) {

	(void)type_descriptor;	/* Unused argument */
	(void)struct_ptr;	/* Unused argument */
	(void)cb;	/* Unused argument */
	(void)key;	/* Unused argument */

	/* Nothing to check */
	return 0;
}

int
asn_generic_unknown_constraint(asn_TYPE_descriptor_t *type_descriptor,
	const void *struct_ptr, asn_app_consume_bytes_f *cb, void *key) {

	(void)type_descriptor;	/* Unused argument */
	(void)struct_ptr;	/* Unused argument */
	(void)cb;	/* Unused argument */
	(void)key;	/* Unused argument */

	/* Unknown how to check */
	return 0;
}

struct __fill_errbuf_arg {
	char  *errbuf;
	size_t errlen;
	size_t erroff;
};

static int
__fill_errbuf(const void *buffer, size_t size, void *app_key) {
	struct __fill_errbuf_arg *arg = (struct __fill_errbuf_arg *)app_key;
	size_t avail = arg->errlen - arg->erroff;

	if(avail > size)
		avail = size + 1;

	switch(avail) {
	default:
		memcpy(arg->errbuf + arg->erroff, buffer, avail - 1);
		arg->erroff += avail - 1;
	case 1:
		arg->errbuf[arg->erroff] = '\0';
	case 0:
		return 0;
	}

}

int
asn_check_constraints(asn_TYPE_descriptor_t *type_descriptor,
	const void *struct_ptr, char *errbuf, size_t *errlen) {

	if(errlen) {
		struct __fill_errbuf_arg arg;
		int ret;

		arg.errbuf = errbuf;
		arg.errlen = *errlen;
		arg.erroff = 0;
	
		ret = type_descriptor->check_constraints(type_descriptor,
			struct_ptr, __fill_errbuf, &arg);
	
		if(ret == -1)
			*errlen = arg.erroff;

		return ret;
	} else {
		return type_descriptor->check_constraints(type_descriptor,
			struct_ptr, 0, 0);
	}
}

void
_asn_i_log_error(asn_app_consume_bytes_f *cb, void *key, const char *fmt, ...) {
	char buf[64];
	char *p;
	va_list ap;
	ssize_t ret;
	size_t len;

	va_start(ap, fmt);
	ret = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	if(ret < 0) {
		/*
		 * The libc on this system is broken.
		 */
		ret = sizeof("<broken vsnprintf>") - 1;
		memcpy(buf, "<broken vsnprintf>", ret + 1);
		/* Fall through */
	}

	if(ret < (ssize_t)sizeof(buf)) {
		(void)cb(buf, ret, key);
		return;
	}

	/*
	 * More space required to hold the message.
	 */
	len = ret + 1;
	p = (char *)alloca(len);
	if(!p) return;	/* Can fail on !x86. */

	
	va_start(ap, fmt);
	ret = vsnprintf(p, len, fmt, ap);
	va_end(ap);
	if(ret < 0 || ret >= (ssize_t)len) {
		ret = sizeof("<broken vsnprintf>") - 1;
		memcpy(buf, "<broken vsnprintf>", ret + 1);
		p = buf;
	}

	(void)cb(p, ret, key);
}
