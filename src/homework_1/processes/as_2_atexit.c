#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    printf("func1() is called\n");
}

void func2(void) {
    printf("func2() is called\n");
}

int main(void) {

    atexit(func1);
    atexit(func2);

    exit(0);

    return 0;
}

