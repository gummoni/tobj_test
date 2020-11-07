#ifndef __RTYPE_H__
#define __RTYPE_H__

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
#define RTYPE(type_name) { #type_name, sizeof(type_name) }
#define RPROP(type_name, prop_name) { #prop_name, sizeof(((type_name*)_dummy)->prop_name) }

//Type情報
typedef struct {
	const char* name;
	uint8_t size;
} rtype;

//type用関数
extern const rtype* __rtypeof(const char* name);
#define rtypeof(type) __rtypeof(#type)

//Prop情報
typedef struct {
	uint32_t offset;
	uint8_t size;
} rprop;

//Prop用関数
#define try_prop_get(self, prop_name, result) __try_prop_get(self, #prop_name, result)
extern bool __try_prop_get(const rtype* self, const char* prop_name, rprop* result);
extern value* prop_value_get(rprop* self, void* obj);
extern void prop_value_set(rprop* self, void* obj, void* data);

#endif//__RTYPE_H__
