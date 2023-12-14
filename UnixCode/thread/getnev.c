/*
    #include <stdlib.h>

    // ISO C
    char *getenv(const char *name);
        argument:
            - name:

        return:
            - 成功返回指向环境变量的指针
            - 未找到返回 NULL
 */

// #include <stdlib.h>
// #include <stdio.h>
// 
// int main() {
//     // char *path = getenv("PATH");
//     // printf("%s\n", path);
//     char buf[1024] = {};
//     int ret = putenv(buf);
//     printf("%s\n", buf);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int global1;
int global2 = 1;

void func(int a, int b, int c) {
    // 自右向左向栈中压入 c 再 b 最后是 a
    // 栈自高地址向低地址，故参数 a 的地址最小
    printf("%p %p %p\n", &a, &b, &c);
}

int main() {
    // 环境变量
    char **env = environ;
    printf("%p\n", *env);
    // while(*env){
    //     printf("(%p) (%p) %s\n",env,*env,*env);
    //     env++;
    // }
    // 全局变量
    printf("%p %p\n", &global1, &global2);
    // 栈
    // 函数参数
    func(1, 2, 3);
    int local1, local2;
    printf("%p %p\n", &local1, &local2);
    // 堆
    char *localc1 = (char *)malloc(1), *localc2 = (char *)malloc(1);
    printf("%p %p\n", localc1, localc2);

    free(localc1);
    free(localc2);
    return 0;
}

/**
0x7fffffffe02a
0x55555555802c 0x555555558010
0x7fffffffdc5c 0x7fffffffdc58 0x7fffffffdc54
0x7fffffffdc78 0x7fffffffdc7c
0x5555555596b0 0x5555555596d0
*/