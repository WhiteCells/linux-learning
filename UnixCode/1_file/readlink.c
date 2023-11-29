/*
    #include <unistd.h>

    // 读取符号链接
    ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);
        argument:
            - pathname: 符号链接路径
            - buf: 缓冲区，用于存储读取到的符号链接目标路径
            - bufsiz: 缓冲区的大小

        return:
            - 成功返回读取到的字节数
            - 失败返回 -1，设置 errno

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <unistd.h>

    ssize_t readlinkat(int dirfd, const char *pathname,
                       char *buf, size_t bufsiz);
        argument:
            - dirfd:
                - AT_FDCWD: 行为与 readlink 相同  
                - 如果 dirfd 是一个打开的目录的文件描述符，
                  pathname 将被解释为相对于该目录的路径
            - pathname: 符号链接路径
            - buf: 缓冲区，用于存储读取到的符号链接目标路径
            - bufsiz: 缓冲区的大小

        return:
            - 成功返回读取到的字节数
            - 失败返回 -1，设置 errno
 */

#include <unistd.h>
#include <stdio.h>

int main() {
    char buf[1024] = {};
    ssize_t siz = readlink("test2", buf, sizeof buf);
    printf("%s\n%ld", buf, siz);
    return 0;
}

