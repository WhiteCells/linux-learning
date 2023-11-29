/*
    #include <sys/stat.h>

    // 修改文件的权限位的前提是:
    // 进程的有效用户 ID 必须等于文件的所有者 ID，
    // 或者进程必须具有超级用户权限

    // 对文件 pathname 进行修改
    int chmod(const char *pathname, mode_t mode);

    // 对已打开的文件( fd 指定)进行修改
    int fchmod(int fd, mode_t mode);

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <sys/stat.h>

    // 对已打开目录 fd 下的 pathname 文件进行修改
    int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags);
 */

// main.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    printf("%d\n",argc);
    for(int i = 0;i < argc; i++) {     // argv[argc]为NULL
        printf("%s\n",argv[i]);
    }
    return 0;
}