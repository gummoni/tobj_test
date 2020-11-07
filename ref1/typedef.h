#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__
#include "main.h"


static const type_info t_hello[] = {
	_TYPE(hello)		,
	_PROP(hello, foo)	,
	_PROP(hello, bar)	,
};

static const type_info t_hello2[] = {
	_TYPE(hello)		,
	_PROP(hello, foo)	,
	_PROP(hello, bar)	,
};

static const type_info* types[] = {
	t_hello,
	t_hello2,
};


#endif//__TYPEDEF_H__
