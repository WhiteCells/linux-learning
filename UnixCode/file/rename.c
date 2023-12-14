/*
    #include <stdio.h>

    // oldpath 指定的文件或目录重命名为 newpath 给定的新名称。
    // 如果 newpath 已经存在，现有文件或目录将被替换
    // 不能对 . 和 .. 重命名
    // 如果 oldname 和 newname 引用统一文件，则函数不作任何修改成功返回

    int rename(const char *oldpath, const char *newpath);

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <stdio.h>

    int renameat(int olddirfd, const char *oldpath,
                int newdirfd, const char *newpath);

    int renameat2(int olddirfd, const char *oldpath,
                    int newdirfd, const char *newpath, unsigned int flags);
 */

#include <stdio.h>

int main() {
    int ret = rename("test.txt", "test1.txt");
    if (-1 == ret) {
        perror("rename");
        return 0;
    }
    return 0;
}