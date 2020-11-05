#include <stdio.h>
#include <stdint.h>
#include "crc32.h"
#include "obj.h"

//オブジェクト作成
pobj obj_create(int size, int length, char* name, void* value) {
	int name_size = strlen(name) + 1;
	int obj_size = sizeof(obj);

	pobj result = malloc(obj_size);
	if (NULL == result->name) return NULL;

	result->name = malloc(name_size);
	if (NULL == result->name) return NULL;

	strcpy_s(result->name, name_size, name);
	result->name_hash = crc32_calc(name, name_size);

	result->size = size;
	result->length = length;
	if (0 == result->length) {
		//プリミティブ（値型）
		switch (result->size) {
		case 1:
			result->value.u8 = *((uint8_t*)value);
			break;

		case 2:
			result->value.u16 = *((uint16_t*)value);
			break;

		case 4:
			result->value.u32 = *((uint32_t*)value);
			break;

		case 8:
			result->value.u64 = *((uint64_t*)value);
			break;
		}
	}
	else {
		//配列（参照型）
		result->value.ptr = value;
	}

	return result;
}

//オブジェクト破棄
void obj_free(pobj self) {
	free(self->name);
	free(self);
}

//ハッシュ取得
uint32_t obj_hash_get(pobj self, uint32_t index) {
	if (0 == self->length) {
		return crc32_calc(self->value.pu8, self->size);
	}
	else if (index < self->length) {
		int size = self->size;
		int offset = size * index;
		return crc32_calc(&self->value.pu8[offset], size);
	}
	else {
		return 0;
	}
}
