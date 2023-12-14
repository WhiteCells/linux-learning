/*
    #include <unistd.h>
    #include <sys/types.h>

    // 通过 path 将文件截断为指定长度
    int truncate(const char *path, off_t length);
        argument:
            - path: 需要被截断的文件路径
            - length: 
                - < 小于文件长度，超出 length 以外的数据不能访问
                - > 大于文件长度，文件长度增加，
                    在之前的文件尾端和新的文件尾端之间的数据将读作 0（创建空洞）
        return:
            - 成功返回 0
            - 失败返回 -1，并设置 errno

    // 通过 fd 将文件截断为指定长度
    int ftruncate(int fd, off_t length);

 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDWR);
    struct stat f_stat;
    fstat(fd, &f_stat);
    size_t sz = f_stat.st_size;
    printf("%lu\n", sz);
    // truncate("test.txt", sz + 1);

    char buf[128] = {};
    int len = read(fd, buf, sizeof buf);
    printf("%s\n%d", buf, len);
    close(fd);
    return 0;
}