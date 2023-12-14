/*
    #include <stdio.h>

    // pathname 方式打开
    FILE *fopen(const char *pathname, const char *mode);
        argument:
            - pathname: 文件路径
            - mode: 指定对 I/O 流的读写方式，字符串的形式
                    b 是区分二进制文件和文本文件，Unix 内核不区分
                - r 或 rb: 为读打开
                - w 或 wb: 将文件截断至 0，或为写而创建
                - a 或 ab: 追加，为文件尾写打开，或为写而创建
                - r+ 或 r+b 或 rb+: 为读和写打开
                - w+ 或 w+b 或 wb+: 将文件截断至 0，或为读和写而打开或创建
                - a+ 或 a+b 或 ab+: 为在文件末读和写而打开或创建
        return:
            - 成功返回文件指针
            - 失败返回 NULL

    // fd 方式打开
    FILE *fdopen(int fd, const char *mode);

    FILE *freopen(const char *pathname, const char *mode, FILE *stream);
        argument:
            - stream: 指定的流，若 fd 已经打开，则先关闭该流，若已指向，则清除指向

 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    FILE *fptr = fopen("test.txt", "w+");
    if (NULL == fptr) {
        perror("fopen");
        return 0;
    }
    for (int i = 1; i < 10; ++i) {
        char buf[1024] = {};
        // 向文件流中写入
        int ret = fprintf(fptr, "row: %d", i);
        // 冲洗指定文件流
        // fflush(fptr);
        // 文件指针移动到当前行开始
        // fseek(fptr, -ret, SEEK_CUR); 
        // 读取该行
        // fgets(buf, 1024, fptr);
        // printf("%s\n", buf);
        // 文件指针换行
        fputs("\n", fptr);
        sleep(1);
    }
    fclose(fptr);
    return 0;
}
