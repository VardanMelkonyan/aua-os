#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	int status;

	if (pid)
	{
		wait(&status);
		printf("Child1 status: %d\n", WEXITSTATUS(status));
		
		pid_t pid_2 = fork();

		if (pid_2)
		{
			waitpid(pid_2, &status, 0);
			printf("Child2 status: %d\n", WEXITSTATUS(status));

			printf("Parent process id: %d\n", getpid());
		}
		else
		{
			printf("Child2 process id: %d\n", getpid());
			return 2;
		}
	}
	else
	{
		printf("Child1 process id: %d\n", getpid());
		return 1;
	}


	return 0;
}
