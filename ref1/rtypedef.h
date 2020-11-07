#ifndef __RTYPEDEF_H__
#define __RTYPEDEF_H__
#include "main.h"


static const rtype t_hello[] = {
	RTYPE(hello)		,
	RPROP(hello, foo)	,
	RPROP(hello, bar)	,
};

static const rtype t_hello2[] = {
	RTYPE(hello)		,
	RPROP(hello, foo)	,
	RPROP(hello, bar)	,
};

static const rtype* types[] = {
	t_hello,
	t_hello2,
};


#endif//__TYPEDEF_H__
