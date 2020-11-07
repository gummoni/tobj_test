#ifndef _BUF_H__
#define _BUF_H__

typedef struct buf {
	void* value;
	int32_t size;
	int32_t length;
} buf;

extern void buf_resize(buf* self, int length);
extern void buf_remove(buf* self, int index);
extern void buf_add(buf* self, int index, void* value);


#endif
