#include <stdio.h>
#include <stdint.h>
#include "crc32.h"
#include "obj.h"

//�I�u�W�F�N�g�쐬
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
		//�v���~�e�B�u�i�l�^�j
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
		//�z��i�Q�ƌ^�j
		result->value.ptr = value;
	}

	return result;
}

//�I�u�W�F�N�g�j��
void obj_free(pobj self) {
	free(self->name);
	free(self);
}

//�n�b�V���擾
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
