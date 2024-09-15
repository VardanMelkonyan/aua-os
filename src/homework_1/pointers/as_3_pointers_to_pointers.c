#include<stdio.h>

int main(void)
{
	int n = 5;

	int *ptr = &n;
	int **ptr_to_ptr = &ptr;

	printf("value using ptr: %d\n", *ptr);
	printf("value using double-ptr: %d\n", **ptr_to_ptr);


	return 0;
}
