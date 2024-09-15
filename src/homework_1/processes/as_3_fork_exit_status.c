#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1: pid = %d, exiting with code 1\n", getpid());
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2: pid = %d, exiting with code 2\n", getpid());
        exit(2);
    }

    waitpid(pid1, &status, 0);
    printf("Parent: Child 1 exited with status %d\n", WEXITSTATUS(status));

    waitpid(pid2, &status, 0);
    printf("Parent: Child 2 exited with status %d\n", WEXITSTATUS(status));

    exit(0);

    return 0;
}

