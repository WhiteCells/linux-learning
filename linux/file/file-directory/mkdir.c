/*
    // 创建目录
    #include <sys/stat.h>
    #include <sys/types.h>

    int mkdir(const char *pathname, mode_t mode);
        argument:
            - pathname: 要创建的目录的路径名
            - mode: 新目录的访问权限 mode & ~umask & 0777 最终权限
        return:
            -  0: success
            - -1: error
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    system("ls -l");

    int ret = mkdir("test-dir", 0777); // drwxr-xr-x 2 eorys eorys  4096 Aug 25 14:47 test-dir
    if (-1 == ret) {
        perror("mkdir");
        return -1;
    }
    printf("successfully created folder\n");

    system("ls -l");

    return 0;
}