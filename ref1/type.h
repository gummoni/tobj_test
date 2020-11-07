#ifndef __TYPE_H__
#define __TYPE_H__

//オブジェクト構造体
typedef struct prop {
	char* name;
	uint32_t size;
	uint32_t length;		//0=値, 1以上=配列
	union {
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

		void* ptr;
		char* str;

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
	} value;

} prop, *props;


extern void* _dummy;

#define nameof(name) #name
#define _TYPE(type_name) { #type_name, sizeof(type_name) }
#define _PROP(type_name, prop_name) { #prop_name, sizeof(((type_name*)_dummy)->prop_name) }

typedef struct {
	const char* name;
	uint8_t size;
} type_info, *ptype_info;

extern const ptype_info typeof(const char* name);


#endif//__TYPE_H__
