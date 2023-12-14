/*
    #include <stdlib.h>

    // ISO C 标准库函数
    // 规定，一个进程最多登记 32 个函数
    // 可用 sysconf 查看限制值，通常系统提供的多余 32 个
    // 用于注册在程序退出时需要执行的函数
    // 注册的函数会按照它们被注册的顺序逆序执行，先注册的后执行
    int atexit(void (*function)(void));
        argument:
            - function: 指向需要注册的函数的指针
                        该函数不接受任何参数，也没有返回值
        return:
            - 成功返回 0
            - 失败返回非 0
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void test01() {
    printf("---\n");
    sleep(1);
}

int main() {
    atexit(test01);
    printf("main\n");
    char *path = getenv("PATH");
    if (path) {
        printf("%s\n", path);
    }
    return 0;
}
