#ifndef __RTYPEDEF_H__
#define __RTYPEDEF_H__
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "buf.h"
#include "main.h"

typedef struct info {
	const char* name;
	void* ptr;
	bool is_ptr;
	int size;
} info;

//Œ^î•ñ‹L‰¯—p
typedef union object {
	info info;
	//-------------------------
	aaa aaa;
	buf buf;
	//-------------------------
} object;

extern object _;
extern info* value_get(void* obj, const char* key);
extern bool info_val_set(info* pobj, size_t value);
extern bool info_ptr_set(info* pobj, void* value);


//#define pcast(obj, type) ((type*)((info*)(obj))->ptr)
#define nameof(text) #text
#define castof(obj, type) ((type*)(obj))
#define CPTR(prop) { #prop, (object *)&prop, true, sizeof(*prop) }
#define CARY(prop) { #prop, (object *)&prop, true, sizeof(prop) / sizeof(*prop) }
#define CVAL(prop) { #prop, (object *)&prop, false, sizeof(prop) }

const static info types[] = {
	//-------------------------
	CVAL(_.aaa.a),
	CVAL(_.aaa.b),
	CPTR(_.aaa.c),
	//-------------------------
};


#endif//__TYPEDEF_H__
