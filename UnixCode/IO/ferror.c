/*
    #include <stdio.h>

    // 每个流在 FILE 对象中维护两个标志
    // 1. 文件出错标志
    // 2. 文件结束标志
    // clearerr 清除这两个标志
    void clearerr(FILE *stream);

    int feof(FILE *stream);
        return: 
            - 条件为真返回非 0
            - 条件为假返回 0

    int ferror(FILE *stream);

    int fileno(FILE *stream);
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR);
    printf("%d\n", fd);
    FILE *fptr = fdopen(fd, "r+");
    close(fd);
    int ret = fileno(fptr);
    printf("%d\n", ret);
    close(ret);
    return 0;
}