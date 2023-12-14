/*
    #include <sys/types.h>
    #include <unistd.h>

    // 重新定位读/写文件偏移
    off_t lseek(int fd, off_t offset, int whence);
        argument:
            - fd: 打开的文件的文件描述符
            - offset: 偏移量，单位字节
            - whence:
                - SEEK_SET: 设置为相对于文件开头的位置的偏移字节
                - SEEK_CUR: 设置为其当前位置加上偏移字节
                - SEEK_END: 设置为文件的大小加上偏移字节
        return:
            - 成功返回从文件开头开始以字节为单位测量的结果偏移位置
            - 失败返回 -1，并设置 errno
 */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 省略返回值判断
int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0777);

    // 写文件
    const char *str = "this is a test";
    write(fd, str, strlen(str));

    // 设置文件偏移量到文件开始第 5 个字节
    lseek(fd, 5, SEEK_SET);
    
    // 读文件
    char buf[128] = {};
    read(fd, buf, 128);
    printf("%s\n", buf);

    close(fd);
    return 0;
}
