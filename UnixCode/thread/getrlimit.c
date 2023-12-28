/*
    #include <sys/time.h>
    #include <sys/resource.h>

    // 获取进程资源限制
    int getrlimit(int resource, struct rlimit *rlim);
        argument:
            - resource: 相应的进程资源，可以设置为以下值
                - RLIMIT_AS: 进程总的可用存储空间的最大字节长度
                             影响到 sbrk 函数和 mmap 函数
                - RLIMIT_CORE: core 文件的最大字节数
                               如果为 0，则阻止创建 core 文件
                - RLIMIT_CPU: CPU 时间的最大量值（秒）
                              超出此软限制时，向该进程发送 SIGXCPU 信号
                - RLIMIT_FSIZE: 可以创建的文件的最大字节长度
                                超出此软限制时，向该进程发送 SIGXFSX 信号
                - RLIMIT_MEMLOCK: 使用 mlock 能够锁定在存储空间中的最大字节长度
                - RLIMIT_MSGQUEUE: 进程 POSIX 消息队列可分配的最大字节数
                - RLIMIT_NICE: 进程的调度优先级
                - RLIMIT_NOFILE: 能打开的最多文件数
                                 更改此限制将影响到 sysconf 函数在参数 _SC_OPEN_MAX 中返回值
                - RLIMIT_NPROC: 每个实际用户 ID 可以拥有的最大子进程数
                                 更改此限制将影响到 sysconf 函数在参数 _SC_CHILD_MAX 中返回值
                - RLIMIT_RSS: 最大驻内存集字节长度
                - RLIMIT_SIGPENDING: 可以排队的信号的最大数量
                                     这个限制由 sigqueue 函数实施的
                - RLIMIT_STACK: 栈的最大字节长度

            - rlim: 获取的相应资源的限制信息

        return:
            - 成功返回 0
            - 失败返回非 0

    // 修改进程资源限制
    // 任何进程可以修改其软限制值，但必须小于或等于其硬限制值
    // 任何进程可以降低其硬限制值，但必须大于或等于其软限制值
    // 只有超级用可以提高其硬限制值
    int setrlimit(int resource, const struct rlimit *rlim);
        argument:
            - rlim: 设置的相应资源的现在信息

    // 
    int prlimit(pid_t pid, int resource, const struct rlimit *new_limit,
                struct rlimit *old_limit);
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    struct rlimit rlim;

    // 获取当前进程的最大文件大小限制
    if (getrlimit(RLIMIT_FSIZE, &rlim) == 0) {
        printf("Current RLIMIT_FSIZE: soft=%lu, hard=%lu\n", rlim.rlim_cur, rlim.rlim_max);
    } else {
        perror("getrlimit");
        return 1;
    }

    // 修改当前进程的最大文件大小限制
    rlim.rlim_cur = 1024 * 1024;  // 设置软限制为1MB
    rlim.rlim_max = 2048 * 1024;  // 设置硬限制为2MB
    if (setrlimit(RLIMIT_FSIZE, &rlim) == 0) {
        printf("New RLIMIT_FSIZE: soft=%lu, hard=%lu\n", rlim.rlim_cur, rlim.rlim_max);
    } else {
        perror("setrlimit");
        return 1;
    }

    // 获取当前进程的最大文件大小限制（修改后）
    if (getrlimit(RLIMIT_FSIZE, &rlim) == 0) {
        printf("Updated RLIMIT_FSIZE: soft=%lu, hard=%lu\n", rlim.rlim_cur, rlim.rlim_max);
    } else {
        perror("getrlimit");
        return 1;
    }

    return 0;
}
