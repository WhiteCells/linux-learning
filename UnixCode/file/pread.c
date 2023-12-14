/*
    #include <unistd.h>

    // 调用 pread 相当于优先调用 lseek 再调用 read
    // 调用 praed 时无法中断其定位和读操作
    // 不会更新当前文件偏移量
    ssize_t pread(int fd, void *buf, size_t count, off_t offset);
        argument:
            - fd: 打开的文件描述符
            - buf: 读出数据存放的缓冲区
            - count: 预期读出文件的字节数
            - offset: 从文件指定偏移量开始执行 read

        return:
            - 成功返回读取的字节数
            - 失败返回 -1， 并设置 errno
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// 忽略返回值判断
int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);

    write(fd, "this is test", 12);

    char buf[1024] = {};
    pread(fd, buf, sizeof(buf), 5);
    printf("%s\n", buf);

    close(fd);
    return 0;
}