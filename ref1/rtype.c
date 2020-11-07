#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "crc32.h"
#include "rtype.h"
#include "rtypedef.h"

void* _dummy;

//Type情報取得
const rtype* __rtypeof(const char* name) {
	const int length = sizeof(types) / sizeof(rtype);
	for (int index = 0; index < length; index++) {
		const rtype* _type = types[index];
		if (0 == strcmp(name, _type->name)) {
			return _type;
		}
	}
	return NULL;
}

//Type情報からProp情報取得
bool __try_prop_get(const rtype* self, const char* prop_name, rprop* result) {
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

//Prop情報を使って構造体ポインタ取得
object* prop_value_get(rprop* self, void* obj) {
	return (object*)((void*)((uint32_t)obj + self->offset));
}

//Prop情報を使って構造体ポインタに値書込み
void prop_value_set(rprop* self, void* obj, void* data) {
	object* pval = prop_value_get(self, obj);
	switch (self->size) {
	case 1:
		pval->u8 = (uint8_t)data;
		break;
	case 2:
		pval->u16 = (uint16_t)data;
		break;
	case 4:
		pval->u32 = (uint32_t)data;
		break;
	case 8:
		pval->u64 = (uint64_t)data;
		break;
	}
}