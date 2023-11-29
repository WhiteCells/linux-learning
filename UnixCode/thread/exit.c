/*
    #include <stdlib.h>

    // 先执行一些清理处理，然后进入内核
    // 刷新缓冲区
    void exit(int status);
        argument:
            - status: 终止状态

    #include <unistd.h>

    // 立即进入内核
    // 不刷新缓冲区
    void _exit(int status);

    #include <stdlib.h>

    // 立即进入内核
    // 不刷新缓冲区
    void _Exit(int status);
 */
