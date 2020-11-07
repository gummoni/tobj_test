#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "crc32.h"
#include "type.h"
#include "typedef.h"

void* _dummy;

//Type情報取得
const type_info* __typeof(const char* name) {
	const int length = sizeof(types) / sizeof(type_info);
	for (int index = 0; index < length; index++) {
		const type_info* _type = types[index];
		if (0 == strcmp(name, _type->name)) {
			return _type;
		}
	}
	return NULL;
}

//Type情報からProp情報取得
bool __try_prop_get(const type_info* self, const char* prop_name, prop_info* result) {
	result->offset = 0;
	uint32_t length = self->size;

	while (result->offset < length) {
		self++;
		if (0 == strcmp(prop_name, self->name)) {
			result->size = self->size;
			return true;
		}
		result->offset += self->size;
	}

	return false;
}

//Prop情報から構造体ポインタ取得
value* prop_value_get(prop_info* self, void* obj) {
	return (value*)((void*)((uint32_t)obj + self->offset));
}
