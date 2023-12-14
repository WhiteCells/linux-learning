/*
    #include <stdio.h>

    // 设置流的缓冲类型
    void setbuf(FILE *stream, char *buf);
        argument:
            - stream: 打开的文件对象的指针
            - buf: 指向缓冲区的指针，长度为 BUFSIZ 定义在 stdio.h

        return:
            - 成功返回 0
            - 失败返回非 0，设置 errno

    void setbuffer(FILE *stream, char *buf, size_t size);
        argument:
            - size: 缓冲长度

    void setlinebuf(FILE *stream);

    int setvbuf(FILE *stream, char *buf, int mode, size_t size);
        argument:
            - mode: 指定缓冲区类型
                - _IOFBF: 全缓冲
                - _IOLBF: 行缓冲
                - _IONBF: 不带缓冲，此时忽略 buf 和 size 参数

    note:
        - 在一个函数内分配自动类型（栈）的标准 I/O 缓冲区
          为了防止内存泄漏，从该函数返回之前必须关闭流
        - 某些操作系统默认缓冲区的一部分存放自己的管理操作信息，
          可以存放在缓冲区的实际字节将少于 size
        - 通常使用系统自动选择缓冲区大小并自动分配缓冲区，
          这种情况下关闭流，标准 I/O 库会自动释放缓冲区
 */


#include <stdio.h>
#include <unistd.h>

int main() {
    // setbuf(stdout, NULL);
    char buf[1024] = {};
    setvbuf(stdout, buf, _IOFBF, 1024);
    BUFSIZ;
    printf("test\n");
    while (1) {
        sleep(3);
        break;
    }
    return 0;
}