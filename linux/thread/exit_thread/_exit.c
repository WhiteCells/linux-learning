/*
    // 退出进程，unix 标准库，不刷新缓冲区
    #include <unistd.h>

    void _exit(int status);
        argument:
            - status: 进程退出时的一个状态信息，父进程在回收子进程资源的时候可以获取到

    #include <stdlib.h>

    void _Exit(int status);
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("111\n");
    printf("222");
    _exit(0); // 不刷新缓冲区
    _Exit(0);
    return 0;
}