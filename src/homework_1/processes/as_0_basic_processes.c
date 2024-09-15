#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = fork();

	if (pid)
		printf("Parent ");
	else
		printf("Child ");

	printf("process id: %d\n", getpid());

	return 0;
}
