#ifndef __RTYPEDEF_H__
#define __RTYPEDEF_H__
#include "main.h"


//å^èÓïÒãLâØóp
typedef union object {
	info info;
	//-------------------------
	aaa aaa;
	buf buf;
	//-------------------------
} object;

extern object _;

const static info types[] = {
	//-------------------------
	CVAL(_.aaa.a),
	CVAL(_.aaa.b),
	CPTR(_.aaa.c),
	//-------------------------
};


#endif//__TYPEDEF_H__
