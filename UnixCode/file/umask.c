/*
    #include <sys/types.h>
    #include <sys/stat.h>

    // 为进程设置文件模式创建屏蔽字，并返回之前的值
    // 子进程的文件模式创建屏蔽字不会影响父进程。
    // 如果子进程修改了文件模式创建屏蔽字，父进程的文件模式创建屏蔽字不会改变
    //（如shell在调用一个会修改文件创建屏蔽字的程序前后使用umask打印文件创建屏蔽字，不会发生改变）
    mode_t umask(mode_t mask);
        argument:
            - mask: 同 open 函数 mode

        return: 此系统调用始终成功，并返回 mask 的上一个值
 */
