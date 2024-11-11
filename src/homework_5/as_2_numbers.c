#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*print_numbers(void *arg)
{
	int	thread_num = *(int *)arg;

	for (int i = 1; i <= 5; i++)
		printf("Thread %d: %d\n", thread_num, i);

	return NULL;
}

int		main(void)
{
	pthread_t	tid[3];
	int			thread_nums[3];
	int			status;

	for (int i = 0; i < 3; i++)
	{
		thread_nums[i] = i + 1;
		status = pthread_create(&tid[i], NULL, print_numbers, &thread_nums[i]);
		if (status)
		{
			printf("Unable to create thread %d\n", i + 1);
			exit(1);
		}
	}

	for (int i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);

	return 0;
}

