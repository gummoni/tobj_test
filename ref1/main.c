#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "rtype.h"


typedef struct prop {
	void* value;
	int size;
} prop;

typedef struct aaa {
	int a;
	int b;
} aaa;

typedef union {
	short *a1;
	char b;
	aaa aaa;
	prop prop;
} gobj;

gobj _;


typedef struct {
	const char* name;
	void* ptr;
	bool is_ptr;
	int size;
} info;

#define msg(text) #text
const char* msg[] = {
	msg(_),
	msg(_.a1),
};

#define CPTR(prop) { #prop, &prop, true, sizeof(*prop) }
#define CVAL(prop) { #prop, &prop, false, sizeof(prop) }

const static info types[] = {
	CPTR(_.a1),
	CVAL(_.aaa.a),
	CVAL(_.aaa.b),
	CVAL(_.b),
};


static void* get(void* obj, const char* key) {
	for (int i = 0; i < sizeof(types) / sizeof(info); i++) {
		info* pinfo = &types[i];
		if (0 == strcmp(key, pinfo->name)) {
			size_t address = (size_t)pinfo->ptr - (size_t)&_;
			_.prop.size = pinfo->size;
			_.prop.value = &((uint8_t*)obj)[address];
			return &_.prop;
		}
	}
	return NULL;
}

#define nameof(text) #text
#define castof(obj, type) ((type*)((prop*)obj)->value)

//ƒƒCƒ“ˆ—
int main(void) {

	_.a1 = 0;
	aaa z;
	aaa* zp = &z;
	void* az = get(&z, nameof(_.aaa.a));

	castof(az, aaa)->a = 123;
	castof(az, aaa)->a = 99;
	_.a1 = 1;

	//const rtype* t = rtypeof(hello);

#if 0
	hello h = { 123, "MESSAGE" };
	hello* ph = &h;
	int sb = sizeof(char**);
	int sa = sizeof(char*);
	int s0 = sizeof(uint8_t);
	int s1 = sizeof(object);
	int s2 = sizeof(ph);
	int s3 = sizeof(*ph);
	int s4 = sizeof(hello);
	object* ppp = (void*)ph;
	if (try_prop_get(t, foo, &prop)) {
		object* v = prop_value_get(&prop, &h);
		v->u8 = 233;
		prop_value_set(&prop, &h, 151);
		v->u8 = 100;
	}

	printf("%16x\n", (unsigned)h.bar);

	uint8_t* aa1 = (uint8_t*)&h;
	char* aa2 = &((char*)&h)[16];
	for (int i = 0; i < sizeof(hello); i++) {
		printf("%2d: %02x, %c\n", i, aa1[i], aa1[i]);
	}

	if (try_prop_get(t, bar, &prop)) {
		object* v = prop_array_get(&prop, &h, 0);
		v->str[1] = "0";
		prop_array_set(&prop, &h, 2, '1');
	}
#endif
	return 0;
}
