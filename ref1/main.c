#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "obj.h"


//ƒƒCƒ“ˆ—
int main(void) {

	int values[16];
	pobj o1 = obj_create(sizeof(int), 16, "test", values);

	values[0] = 1234;
	values[1] = 12345;
	values[2] = 12346;
	values[3] = 12347;

	int v1 = o1->value.ps32[0];
	int v2 = o1->value.ps32[1];
	int v3 = o1->value.ps32[2];
	int v4 = o1->value.ps32[3];

	o1->value.ps32[3] = 4444;

	//pobj v1 = obj_create("hello", 1234, 0);
	//pobj v2 = obj_create("world", 2345, 0);

	//int data[5] = { 1,2,3,4,5 };
	//pobj v3 = obj_create("foo", data, 5);

	//((int*)v3->value.ptr)[1] = 33;

	return 0;
}
