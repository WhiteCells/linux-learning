/*
    #include <sys/stat.h>
    #include <sys/types.h>

    // 创建目录
    int mkdir(const char *pathname, mode_t mode);
        argument:
            - pathname: 要创建的目录的路径
            - mode: 指定新目录的权限位，目录至少执行权限位

        return:
            - 成功返回 0
            - 失败返回 -1

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <sys/stat.h>

    int mkdirat(int dirfd, const char *pathname, mode_t mode);
        argument:
            - dirfd:
                - 是一个打开的目录文件描述符，表示新目录的父目录
                - AT_FDCWD: 行为与 mkdir 相同

 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    int ret = mkdir("../pthread", 0333);
    if (-1 == ret) {
        perror("mkdir");
    }
    return 0;
}