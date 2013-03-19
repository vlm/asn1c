/*
 * Singly linked tail queue support.
 */
#ifndef	ASN1_PARSER_LIST_H
#define	ASN1_PARSER_LIST_H

#define	TQ_HEAD(type)					\
	struct {					\
		type *tq_head;				\
		type**tq_tail;				\
	}

#define	TQ_MOVE(to, from)	do {			\
	if(&(TQ_FIRST(from)) == (from)->tq_tail) {	\
		TQ_INIT(to);				\
	} else {					\
		(to)->tq_head = (from)->tq_head;	\
		(to)->tq_tail = (from)->tq_tail;	\
	}						\
	TQ_INIT(from);					\
	} while(0)

#define	TQ_ENTRY(type)					\
	struct {					\
		type *tq_next;				\
	}

#define TQ_FIRST(headp)		((headp)->tq_head)
#define TQ_NEXT(el, field)	((el)->field.tq_next)

#define TQ_INIT(head) do {				\
	TQ_FIRST((head)) = 0;				\
	(head)->tq_tail = &TQ_FIRST((head));		\
	} while(0)

#define	TQ_FOR(var, head, field)			\
	for((var) = TQ_FIRST((head));			\
		(var); (var) = TQ_NEXT((var), field))

/* MSVC does not have typeof(), cannot prevent side effects! */
#define	TQ_ADD(head, xel, field) do {			\
	typeof(xel) __el = (xel);			\
	assert(TQ_NEXT((__el), field) == 0);		\
        *(head)->tq_tail = (__el);			\
        (head)->tq_tail = &TQ_NEXT((__el), field);	\
	} while(0)

#define	TQ_CONCAT(head1, head2, field) do {		\
	if(TQ_FIRST(head2)) {				\
		*(head1)->tq_tail = (head2)->tq_head;	\
		(head1)->tq_tail = (head2)->tq_tail;	\
		TQ_INIT(head2);				\
	}						\
	} while(0)

/*
 * Remove the first element and return it.
 */
#define	TQ_REMOVE(head, field)	({			\
	typeof(TQ_FIRST((head))) __fel;			\
	__fel = TQ_FIRST((head));			\
	if(__fel == 0					\
	|| (TQ_FIRST((head)) = TQ_NEXT(__fel, field))	\
		== 0) {					\
		(head)->tq_tail = &TQ_FIRST((head));	\
	} else {					\
		TQ_NEXT(__fel, field) = 0;		\
	}						\
	__fel; })


#endif	/* ASN1_PARSER_LIST_H */
