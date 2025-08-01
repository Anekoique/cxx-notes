#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++) {
	  printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_pointere(void * x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{
	int a = 12345;
	show_int(a);
	return 0;
}
