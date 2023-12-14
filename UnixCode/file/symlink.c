/*
    #include <unistd.h>

    // 创建符号链接
    // 创建一个指向 target 的新目录项 linkpath
    int symlink(const char *target, const char *linkpath);
        argument:
            - target:
            - linkpath:

        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <unistd.h>

    int symlinkat(const char *target, int newdirfd, const char *linkpath);

 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    // symlink("test.cpp", "test2");

    // sleep(3);
    // unlink("test");
    int fd = open("./", O_DIRECTORY);
    if (-1 == fd) {
        perror("open");
    }
    int  ret = symlinkat("unlink.c", fd, "ukkkk");
    if (-1 == ret) {
        perror("symlinkat");
    }
    return 0;
}
