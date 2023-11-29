#include "head.h"
#include <stdio.h>

/* gcc main.c -I ./include/ -L ./lib -l cal -o main */
/* gcc main.c -o main -I ./include/ -L ./lib -l cal */

/* gcc main.c src/*.c -o main -I./include/ -L./lib/ -lcal */
/* gcc main.c src/*.c -o main -Iinclude -Llib -lcal */
int main() {
    printf("%d\n", add(1, 2));
    printf("%d\n", sub(1, 2));
    printf("%d\n", mult(1, 2));
    printf("%f\n", div(1, 2));

    return 0;
}