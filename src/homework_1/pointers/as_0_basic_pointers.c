#include<stdio.h>

int main(void)
{
	int n = 12;
	int *ptr = &n;
	printf("Print integer address from variable: %p\n", &n);
	printf("Print integer address from pointer: %p\n", ptr);

	printf("Current value: %d\n", n);
	(*ptr)++;
	printf("After modification via pointer: %d\n", n);

	return 0;
}
