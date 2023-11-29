/*
    #include <stdio.h>

    // 解除对一个文件或目录的链接
    // 对于文件，remove 功能与 unlink 相同
    // 对于目录，remove 功能与 rmdir 相同
    int remove(const char *pathname);
        argument:
            - pathname:
        return
            - 成功返回 0
            - 失败返回 -1，设置 errno
 */