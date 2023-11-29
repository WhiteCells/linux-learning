#include "head.h"

int main() {
    int a = 2, b = 1;
    scanf("%d %d", &a, &b);
    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));
    printf("%d\n", mult(a, b));
    printf("%lf\n", div(a, b));
    return 0;
}