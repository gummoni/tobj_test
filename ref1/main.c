#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "buf.h"
#include "rtypedef.h"


//メイン処理
int main(void) {

	int f  = 200;
	int g = 86;
	aaa z;
	aaa* p = castof(&z, aaa);
	p->a = 123;
	p->a = 99;
	p->c = &f;
	int* pc = &f;

	info* inf = value_get(&z, nameof(_.aaa.b));	
	info_val_set(inf, 23);	//値書込み

	info* inf2 = value_get(&z, nameof(_.aaa.c));
	info_val_set(inf2, 55);	//値書込み
	info_ptr_set(inf2, &g);	//ポインタ更新
	info_val_set(inf2, 11);	//値書込み

	return 0;
}
