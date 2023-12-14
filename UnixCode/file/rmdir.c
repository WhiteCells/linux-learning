/*
    #include <unistd.h>

    // 删除目录，只能删除空目录
    // 删除非空目录需要递归的方式删除目录中的内容
    // 调用此函数使目录的链接数成为 0，如果也没有其他进程打开此目录，则释放此目录占用空间
    int rmdir(const char *pathname);
        argument:
            - pathname: 需要删除的目录的路径

        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno
 */

#include <unistd.h>
#include <stdio.h>

int main() {
    int ret = rmdir("../thread");
    if (-1 == ret) {
        perror("rmdir");
        return 0;
    }
    return 0;
}