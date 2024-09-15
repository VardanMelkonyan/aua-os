#include<stdio.h>

int main(void)
{
	int	array[5] = {0, 1, 2, 3, 4};

	int *ptr = &array[0];
	int i = 0;
	while (i++ < 5)
		printf("%d ", *ptr + i);
	printf("\nAfter modification: \n");

	i = 0;
	while (i++ < 5)
	{
		*ptr = -(++(*ptr));
		printf("%d ", *ptr++);
	}
	printf("\n");

	return 0;
}
