#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "main.h"


//ƒƒCƒ“ˆ—
int main(void) {

	const type_info* t = typeof(hello);
	prop_info pinfo;

	hello h = { 123, "MESSAGE" };

	if (try_prop_get(t, foo, &pinfo)) {
		value* v = prop_value_get(&pinfo, &h);
		v->u8 = 233;
		v->u8 = 100;
	}

	return 0;
}
