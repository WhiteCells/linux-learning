/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    // 打开指定路径下文件
    int open(const char *pathname, int flags);
        argument:
            - pathname: 需要打开的文件的路径
            - flags: 
                - 必须包含以下:
                    - O_RDONLY: 只读
                    - O_WRONLY: 只写
                    - O_RDWR: 读写
                - 可以附加 0 个或多个，使用按位或 | 的方式附加
                    - O_APPEND: 文件以追加方式打开，
                                在每次写入 write 之前文件偏移量 offset 位于文件末尾
                                一个原子操作
                    - O_ASYNC: 启用信号驱动 I/O
                    - O_SYNC: 以同步写入方式打开文件，确保写入立即被写入磁盘。
                    - O_DSYNC: 文件写入操作会保证数据的完整性
                    - O_CLOEXEC: (since Linux 2.6.23)文件描述符被传递给一个新的进程（通过 exec 系统调用）时，
                                 这个文件描述符会被自动关闭
                    - O_CREAT: 如果指定路径下文件不存在，将其创建为常规文件
                    - O_DIRECT: 尽量减少此文件的I/O对缓存的影响
                    - O_CLOEXEC: 在执行 exec 系统调用时关闭文件描述符
                    - O_DIRECTORY: 如果路径 pathname 不是目录，则 open 失败
                    - O_EXCL: 与 O_CREAT 一起使用，如果文件已经存在，则 open 失败
                    - O_NOCTTY: 如果文件是终端设备，不将其分配为控制终端
                    - O_LARGEFILE: 处理大文件，这个标志可能已经不再是必需的
                    - O_NOFOLLOW: 直接操作符号链接而不是其指向的文件
                    - O_TMPFILE: 在文件系统中创建一个不与目录关联的临时文件
                    - O_TRUNC: 如果文件存在，将其截断为空文件
                    - O_NONBLOCK: 以非阻塞模式打开文件

        return: 
            - 成功返回最小的未使用的文件描述符
            - 失败返回 -1，并设置 errno
    int open(const char *pathname, int flags, mode_t mode);
        argument:
            - mode: 权限，可以用掩码(0755)的方式也可以用宏最终权限为 mode & ~mask
                - S_IRUSR: 用户读
                - S_IWUSR: 用户写
                - S_IXUSR: 用户执行
                - S_IRGRP: 组读
                - S_IWGRP: 组写          
                - S_IXGRP: 组执行         
                - S_IROTH: 其他读
                - S_IWOTH: 其他写
                - S_IXOTH: 其他执行

    int creat(const char *pathname, mode_t mode);

    int openat(int dirfd, const char *pathname, int flags);
    int openat(int dirfd, const char *pathname, int flags, mode_t mode);
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("../../a.out", O_EXCL);
    if (-1 == fd) {
        perror("open");
        exit(0);
    }
    // printf("hello\n");
    close(fd);
    return 0;
}