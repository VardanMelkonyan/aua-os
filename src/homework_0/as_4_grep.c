#include <stdlib.h>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t ret = fork();

	if (!ret)
	{
		execl("/usr/bin/grep", "grep", "education", "text.txt", NULL);
		
		perror("execl failed");
		exit(1);
	}
	else
	{
		wait(NULL);
		printf("Parent process done\n");
	}
	return 0;
}
