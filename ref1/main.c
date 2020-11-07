#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "rtype.h"
#include "main.h"


//ƒƒCƒ“ˆ—
int main(void) {

	const rtype* t = rtypeof(hello);
	rprop pinfo;

	hello h = { 123, "MESSAGE" };

	if (try_prop_get(t, foo, &pinfo)) {
		value* v = prop_value_get(&pinfo, &h);
		v->u8 = 233;
		prop_value_set(&pinfo, &h, 151);
		v->u8 = 100;
	}

	return 0;
}
