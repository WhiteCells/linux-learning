#include <stdio.h>

int main() {
    int a = 10; // gcc test.c -Wall 显示所有警告
    printf("%d\n", a);
#ifdef DEBUG
    printf("debug information\n"); // gcc test.c -o app -DDEBUG 显示 DEBUG 宏信息
#endif

#ifdef __cplusplus
    printf("used __cplusplus\n"); // g++ test.c -o app 运行 __cplusplus 宏内代码，gcc 则不会
#endif

    return 0;
}