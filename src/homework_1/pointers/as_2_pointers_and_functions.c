#include<stdio.h>

void swap(int *a, int*b)
{
	*a = *b ^ *a;
	*b = *a ^ *b;
	*a = *b ^ *a;
}

int main(void)
{
	int a = 1, b = 2;
	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("After swap:\na: %d, b: %d\n", a, b);

	return 0;
}
