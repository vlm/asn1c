
extern int opt_debug;

#define	ASN_DEBUG(fmt, args...)	do {		\
		if(opt_debug < 2) break;	\
		fprintf(stderr, fmt, ##args);	\
		fprintf(stderr, "\n");		\
	} while(0)
