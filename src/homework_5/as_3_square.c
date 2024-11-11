#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
	int	num;
	int	thread_num;
} ThreadArg;

void	*calc_square(void *arg)
{
	ThreadArg	*data = (ThreadArg *)arg;
	int			n = data->num;

	printf("Thread %d: Square of %d is %d\n", data->thread_num, n, n * n);
	return NULL;
}

int		main(void)
{
	int			numbers[] = {1, 2, 3, 4, 5};
	int			num_threads = sizeof(numbers) / sizeof(numbers[0]);
	pthread_t	tid[num_threads];
	ThreadArg	args[num_threads];
	int			status;

	for (int i = 0; i < num_threads; i++)
	{
		args[i].num = numbers[i];
		args[i].thread_num = i + 1;
		status = pthread_create(&tid[i], NULL, calc_square, &args[i]);
		if (status)
		{
			printf("Unable to create thread %d\n", i + 1);
			exit(1);
		}
	}

	for (int i = 0; i < num_threads; i++)
		pthread_join(tid[i], NULL);

	return 0;
}

