#ifndef __OBJ_H__
#define __OBJ_H__

//オブジェクト構造体
typedef struct obj {
	char* name;
	uint32_t name_hash;

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
} obj, * pobj;


//オブジェクト作成
extern pobj obj_create(int size, int length, char* name, void* value);

//オブジェクト破棄
extern void obj_free(pobj self);


#endif//__OBJ_H__
