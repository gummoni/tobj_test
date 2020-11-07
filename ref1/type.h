#ifndef __TYPE_H__
#define __TYPE_H__

//オブジェクト構造体
typedef union {
	uint8_t u8;
	int8_t s8;
	uint16_t u16;
	int16_t s16;
	uint32_t u32;
	int32_t s32;
	uint64_t u64;
	int64_t s64;
	float flt;
	double dbl;
	uint8_t* pu8;
	int8_t* ps8;
	uint16_t* pu16;
	int16_t* ps16;
	uint32_t* pu32;
	int32_t* ps32;
	uint64_t* pu64;
	int64_t* ps64;
	float* pflt;
	double* pdbl;
	void* ptr;
	char* str;
} value;

//定義用変数
extern void* _dummy;

//Type用Define
#define nameof(name) #name
#define _TYPE(type_name) { #type_name, sizeof(type_name) }
#define _PROP(type_name, prop_name) { #prop_name, sizeof(((type_name*)_dummy)->prop_name) }

//Type情報
typedef struct {
	const char* name;
	uint8_t size;
} type_info;

//type用関数
extern const type_info* __typeof(const char* name);
#define typeof(type) __typeof(#type)

//Prop情報
typedef struct {
	uint32_t offset;
	uint8_t size;
} prop_info;

//Prop用関数
#define try_prop_get(self, prop_name, result) __try_prop_get(self, #prop_name, result)
extern bool __try_prop_get(const type_info* self, const char* prop_name, prop_info* result);
extern value* prop_value_get(prop_info* self, void* obj);


#endif//__TYPE_H__
