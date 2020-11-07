#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "buf.h"


//サイズ変更
void buf_resize(buf* self, int length) {
	if (NULL == self)
		return;

	self->length = length;
	if (0 == length) {
		if (NULL != self->value) {
			free(self->value);
			self->value = NULL;
		}
	}
	else if (NULL == self->value) {
		self->value = malloc(length * self->size);
	}
	else {
		void* ptr = realloc(self->value, length * self->size);
		self->value = ptr;
	}
}

//要素削除
void buf_remove(buf* self, int index) {
	switch (self->size) {
	case 1:
	{
		uint8_t* ptr = (uint8_t*)self->value;
		for (int i = index + 1; i < self->length; i++) {
			ptr[i - 1] = ptr[i];
		}
		break;
	}
	case 2:
	{
		uint16_t* ptr = (uint16_t*)self->value;
		for (int i = index + 1; i < self->length; i++) {
			ptr[i - 1] = ptr[i];
		}
		break;
	}
	case 4:
	{
		uint32_t* ptr = (uint32_t*)self->value;
		for (int i = index + 1; i < self->length; i++) {
			ptr[i - 1] = ptr[i];
		}
		break;
	}
	case 8:
	{
		uint64_t* ptr = (uint64_t*)self->value;
		for (int i = index + 1; i < self->length; i++) {
			ptr[i - 1] = ptr[i];
		}
		break;
	}
	}
	buf_resize(self, self->length - 1);
}

//要素追加
void buf_add(buf* self, int index, void* value) {
	buf_resize(self, self->length + 1);

	switch (self->size) {
	case 1:
	{
		uint8_t* ptr = (uint8_t*)self->value;
		for (int i = self->length - 1; index < i; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = *(uint8_t*)value;
		break;
	}
	case 2:
	{
		uint16_t* ptr = (uint16_t*)self->value;
		for (int i = self->length - 1; index < i; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = *(uint16_t*)value;
		break;
	}
	case 4:
	{
		uint32_t* ptr = (uint32_t*)self->value;
		for (int i = self->length - 1; index < i; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = *(uint32_t*)value;
		break;
	}
	case 8:
	{
		uint64_t* ptr = (uint64_t*)self->value;
		for (int i = self->length - 1; index < i; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = *(uint64_t*)value;
		break;
	}
	}
}
