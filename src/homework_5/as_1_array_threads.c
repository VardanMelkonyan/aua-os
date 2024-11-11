#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int start_idx;
    int end_idx;
    int thread_num;
	int size;
} ThreadArray;

void	*partial_sum(void *arg)
{
    ThreadArray	*data = (ThreadArray *)arg;
    int			sum = 0;

    for (int i = data->start_idx; i < data->end_idx; i++)
        sum += data->array[i];

    printf("Thread %d: Partial sum from index %d to %d is %d\n",
           data->thread_num, data->start_idx, data->end_idx - 1, sum);

    return NULL;
}

int		main(void)
{
	int 		n = 8;
    int			arr[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    pthread_t	threads[2];
    ThreadArray	array_data[2];
	int			status;

    for (int i = 0; i < 2; i++)
	{
        array_data[i].array = arr;
		array_data[i].size = n;
        array_data[i].start_idx = i * (n / 2);
        array_data[i].end_idx = (i + 1) * (n / 2);
        array_data[i].thread_num = i + 1;
        status = pthread_create(&threads[i], NULL, partial_sum, &array_data[i]);

		if (status)
		{
			printf("Unable to create thread, %d", i + 1);
			exit(1);
		}
    }

    for (int i = 0; i < 2; i++)
        pthread_join(threads[i], NULL);

    return 0;
}

