//#ifndef __RTYPE_H__
//#define __RTYPE_H__
//#include <stdint.h>
//#include <stdbool.h>
//
////オブジェクト構造体
//typedef union {
//	uint8_t u8;
//	int8_t s8;
//	uint16_t u16;
//	int16_t s16;
//	uint32_t u32;
//	int32_t s32;
//	uint64_t u64;
//	int64_t s64;
//	float flt;
//	double dbl;
//	uint8_t* pu8;
//	int8_t* ps8;
//	uint16_t* pu16;
//	int16_t* ps16;
//	uint32_t* pu32;
//	int32_t* ps32;
//	uint64_t* pu64;
//	int64_t* ps64;
//	float* pflt;
//	double* pdbl;
//	void* ptr;
//	char* str;
//} object;
//
//
////定義用変数
//extern global _dummy;
//
//
//
////Type用Define
//#define nameof(name) #name
//#define _field(type_name, prop_name) (_dummy. ## type_name ## . ## prop_name)
//#define RTYPE(type_name)					{ #type_name, false,	sizeof(type_name)	}
//#define RPROP(prop_name, is_ptr, length)	{ #prop_name, is_ptr,	length				}
//#define RPROP_PRM(type_name, prop_name)	RPROP(prop_name, false	, &_field(type_name, prop_name))
//#define RPROP_PTR(type_name, prop_name)	RPROP(prop_name, true	, &_field(type_name, prop_name))
//#define RPROP_ARY(type_name, prop_name)	RPROP(prop_name, true	, &_field(type_name, prop_name))
//
////Type情報
//typedef struct {
//	const char* name;
//	uint8_t is_ptr;
//	void *ptr;
//} rtype;
//
////type用関数
//extern const rtype* __rtypeof(const char* name);
//#define rtypeof(type) __rtypeof(#type)
//
////Prop情報
////typedef struct {
////	uint32_t offset;
////	const rtype* info;
////} rprop;
//
////Prop用関数
//try_get_field()
//
//#define try_prop_get(self, prop_name, result) __try_prop_get(self, #prop_name, result)
////extern bool __try_prop_get(const rtype* self, const char* prop_name, rprop* result);
//#define prop_value_get(self, obj)		((object*)(&((uint8_t *)(obj))[(self)->offset]))
////extern object* prop_array_get(rprop* self, void* obj, int index);
////extern bool prop_value_set(rprop* self, void* obj, void* data);
////extern bool prop_array_set(rprop* self, void* obj, int index, void* data);
//
//
//#endif//__RTYPE_H__
