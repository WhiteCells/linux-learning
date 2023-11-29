/*
    #include <unistd.h>

    // 调用 pread 相当于优先调用 lseek 再调用 read
    // 调用 praed 时无法中断其定位和读操作
    // 不会更新当前文件偏移量
    ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
        argument:
            - fd: 打开的文件描述符
            - buf: 写到文件的数据的缓冲区
            - count: 预期写入文件的字节数
            - offset: 从文件指定偏移量开始执行 write

        return: 
            - 成功返回写入的字节数
            - 失败返回 -1，设置 errno
 */
// On success, pread() returns the number of bytes read (a return of zero indicates end of file)
// and pwrite() returns the number of bytes written.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {


    return 0;
}