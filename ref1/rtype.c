#include "rtypedef.h"

object _;


//値取得
info* value_get(void* obj, const char* key) {
	for (int i = 0; i < sizeof(types) / sizeof(info); i++) {
		const info* pinfo = &types[i];
		if (0 == strcmp(key, pinfo->name)) {
			size_t address = (size_t)pinfo->ptr - (size_t)&_;
			_.info.size = pinfo->size;
			_.info.is_ptr = pinfo->is_ptr;
			_.info.ptr = &(((uint8_t*)obj)[address]);
			return &_.info;
		}
	}
	return NULL;
}


static bool __info_val_set1(info* pobj, size_t value) {
	if (NULL != pobj) {
		if (pobj->is_ptr) {
			**((uint8_t**)pobj->ptr) = *(uint8_t*)value;
			return true;
		}
		else {
			*((uint8_t*)pobj->ptr) = *(uint8_t*)value;
			return true;
		}
	}
	return false;
}

static bool __info_val_set2(info* pobj, size_t value) {
	if (NULL != pobj) {
		if (pobj->is_ptr) {
			**((uint16_t**)pobj->ptr) = *(uint16_t*)value;
			return true;
		}
		else {
			*((uint16_t*)pobj->ptr) = *(uint16_t*)value;
			return true;
		}
	}
	return false;
}

static bool __info_val_set4(info* pobj, size_t value) {
	if (NULL != pobj) {
		if (pobj->is_ptr) {
			**((uint32_t**)pobj->ptr) = value;
			return true;
		}
		else {
			*((uint32_t*)pobj->ptr) = value;
			return true;
		}
	}
	return false;
}

static bool __info_val_set8(info* pobj, size_t value) {
	if (NULL != pobj) {
		if (pobj->is_ptr) {
			**((uint64_t**)pobj->ptr) = value;
			return true;
		}
		else {
			*((uint64_t*)pobj->ptr) = value;
			return true;
		}
	}
	return false;
}
bool info_val_set(info* pobj, size_t value) {
	switch (pobj->size) {
	case 1:
		return __info_val_set1(pobj, value);
	case 2:
		return __info_val_set2(pobj, value);
	case 4:
		return __info_val_set4(pobj, value);
	case 8:
		return __info_val_set8(pobj, value);
	default:
		return false;
	}
}


//ポインタ設定
bool info_ptr_set(info* pobj, void* value) {
	if (NULL != pobj) {
		if (pobj->is_ptr) {
			*(void **)(pobj->ptr) = value;
			return true;
		}
	}
	return false;
}
