/*
    #include <unistd.h>

    // 为文件创建别名
    int link(const char *oldpath, const char *newpath);
        argument:
            - oldpath: 现有文件
            - newpath: 创建的新目录项（如果存在则返回出错）
                       只创建最后一个分量，路径中的其他部分应当已经存在
        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <unistd.h>

    int linkat(int olddirfd, const char *oldpath,
               int newdirfd, const char *newpath, int flags);
        argument:
            - olddirfd: 现有目录项所在目录的文件描述符
            - oldpath: 现有文件
            - newdirfd: 新目录项所在目录的文件描述符
            - newpath: 新目录项的文件名
            - flags:
                - 设置了 AT_SYMLINK_NOFOLLOW，创建指向符号链接目标的硬连接
                - 没有设置 AT_SYMLINK_NOFOLLOW，创建指向符号链接本身的硬连接

 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int ret = link("test.cpp", "test");
    if (-1 == ret) {
        perror("link");
    }
    // sleep(3);
    // ret = unlink("test");
    // if (-1 == ret) {
    //     perror("unlink");
    // }
    return 0;
}
