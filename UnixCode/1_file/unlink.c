/*
    #include <unistd.h>
 
    // 删除硬连接
    // 需要对包含该目录项（硬链接）的目录具有写和执行操作
    int unlink(const char *pathname);
        argument:
            - pathname: 如果是符号链接，删除该符号链接（不跟随符号链接）
                        给出符号链接名的情况下，没有一个函数能删除由该链接所引用的文件
        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno
            
    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <unistd.h>

    int unlinkat(int dirfd, const char *pathname, int flags);
        argumnet:
            - dirfd: 
            - pathname:
            - flags:
                - AT_REMOVEDIR: 类似 rmdir
 */

/*
    `unlink` 的特性被程序用来确保即使是在程序崩溃时，
    它所创建的临时文件也不会遗留下来。进程使用 `open` 或 `creat` 创建一个文件，
    然后立即调用 `unlink`，因为该文件依旧是打开的，所以不会将其内容删除，只有当进程关闭该文件或终止时，
    该文件内容才会被删除
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd = open("../../test/", O_RDWR | O_EXCL);
    if (-1 == fd) {
        perror("open");
        exit(0);
    }
    unlinkat(fd, "../../test/", AT_REMOVEDIR);
    sleep(10);
    close(fd);
    return 0;
}
