#include "include/head.h"

/*
gcc -c -fpic a.c b.c
gcc -shared a.o b.o -o libcal.so
 */

int main() {
    printf("%d", add(10, 20));
    printf("%d", add(10, 20));
    printf("%lf", mutl(10, 20.1));
    printf("%lf", div(10, 20));
    return 0;
}
