
extern int opt_debug;

#define	ASN_DEBUG(fmt, args...)	do {		\
		if(opt_debug < 2) break;	\
		fprintf(stderr, fmt, ##args);	\
		fprintf(stderr, " (%s:%d)\n",	\
			__FILE__, __LINE__);	\
	} while(0)

/* Which type is the PDU; for ../../skeletons/asn-decoder-template.c */
#define	asn_DEF	asn_DEF_DataInterChange
