/*
    // 复制文件描述符
    // 获取文件状态标志
    // 设置文件状态标志
    // 非阻塞 I/O
    #include <unistd.h>
    #include <fcntl.h>

    int fcntl(int fd, int cmd, ... );
        arguement:
            - fd: 文件描述符
            - cmd: 操作命令
                - F_SETFL: 设置文件状态标志，设置文件 flags
                    ... arg:
                        必选项: 不可以被修改
                            - O_RDWR
                            - O_RDONLY
                            - O_WRONLY
                        可选: 可以修改
                            - O_APPEND: 追加数据
                            - O_NONBLOCK、O_NDELAY: 设置成非阻塞
                            - O_CREAT
                            - O_DIRECT
                            - O_DIRECTORY
                            - O_DSYNC
                            - O_EXCL
                            - O_LARGEFILE
                            - O_NOATIME
                            -
                - F_DUPFD: 复制文件描述符
                - F_GETFD: 获取文件描述符标志 flags，与 open 函数中传递的参数 flags 相同（get）
                - F_SETFD: 设置文件描述符标志
                - F_GETFL: 获取文件状态标志
                - F_GETLK: 获取文件锁
                - F_SETLK: 设置文件锁
                - F_SETLKW: 设置文件锁，如果锁不可用则阻塞
            - ...: 可变参数
        return:
            - -1: error, set errno
 */

#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 省略返回值判断
int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);

    // 获取文件状态标志
    int fd_flags = fcntl(fd, F_GETFD);

    // 修改文件标志位
    fcntl(fd, F_SETFL, fd_flags | O_APPEND);

    // 写文件
    write(fd, "test", 4);
    write(fd, "test", 4);

    lseek(fd, 0, SEEK_SET);

    // 读文件
    char buf[128] = {};
    read(fd, buf, 128);
    printf("%s\n", buf);
    
    close(fd);
    return 0;
}
