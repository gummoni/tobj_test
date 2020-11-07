//#include <stdio.h>
//#include <stdint.h>
//#include <stdbool.h>
//#include <string.h>
//#include "crc32.h"
//#include "main.h"
//#include "rtype.h"
//#include "rtypedef.h"
//
//global _dummy;
//
//#if 0
////Type情報取得
//const rtype* __rtypeof(const char* name) {
//	const int length = sizeof(types) / sizeof(rtype);
//	for (int index = 0; index < length; index++) {
//		const rtype* _type = types[index];
//		if (0 == strcmp(name, _type->name)) {
//			return _type;
//		}
//	}
//	return NULL;
//}
//#endif
//#if 0
////Type情報からProp情報取得
//bool __try_prop_get(const rtype* self, const char* prop_name, rprop* result) {
//	result->offset = 0;
//	uint32_t length = self->type_size;
//
//	result->info = self;
//	while (result->offset <= length) {
//		result->info++;
//		if (0 == strcmp(prop_name, result->info->name)) {
//			return true;
//		}
//		result->offset += result->info->mem_size;
//	}
//
//	return false;
//}
//
////Prop情報を使って構造体ポインタに値書込み
//bool prop_value_set(rprop* self, void* obj, void* data) {
//	object* pval = prop_value_get(self, obj);
//	if (self->info->is_ptr) {
//		//pointer
//		switch (self->info->type_size) {
//		case 1:
//			*pval->pu8 = *(uint8_t*)data;
//			return true;
//		case 2:
//			*pval->pu16 = *(uint16_t*)data;
//			return true;
//		case 4:
//			*pval->pu32 = *(uint32_t*)data;
//			return true;
//		case 8:
//			*pval->pu64 = *(uint64_t*)data;
//			return true;
//		}
//	}
//	else {
//		//primitive
//		switch (self->info->type_size) {
//		case 1:
//			pval->u8 = (uint8_t)data;
//			return true;
//		case 2:
//			pval->u16 = (uint16_t)data;
//			return true;
//		case 4:
//			pval->u32 = (uint32_t)data;
//			return true;
//		case 8:
//			pval->u64 = (uint64_t)data;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool prop_array_set(rprop* self, void* obj, int index, void* data) {
//	object* pval = prop_array_get(self, obj, index);
//	if (NULL != pval) {
//		//array
//		switch (self->info->type_size) {
//		case 1:
//			*pval->pu8 = *(uint8_t*)data;
//			return true;
//		case 2:
//			*pval->pu16 = *(uint16_t*)data;
//			return true;
//		case 4:
//			*pval->pu32 = *(uint32_t*)data;
//			return true;
//		case 8:
//			*pval->pu64 = *(uint64_t*)data;
//			return true;
//		}
//	}
//	return false;
//}
//
//object* prop_array_get(rprop* self, void* obj, int index) {
//	const rtype* rinfo = self->info;
//	int idx = rinfo->type_size * index;
//	if (idx < rinfo->mem_size) {
//		unsigned ppp = (unsigned)((uint8_t*)obj)[self->offset];
//		uint8_t* ptr = (uint8_t *)ppp;
//		return (object*)&(ptr[self->offset + idx]);
//	}
//	return NULL;
//}
//
//#endif
//
