#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "crc32.h"
#include "type.h"
#include "typedef.h"

void* _dummy;

const ptype_info typeof(const char* name) {
	const int length = sizeof(types) / sizeof(ptype_info);
	for (int index = 0; index < length; index++) {
		ptype_info _type = (const ptype_info)&types[index];
		if (0 == strcmp(name, _type->name)) {
			return _type;
		}
	}
	return NULL;
}

