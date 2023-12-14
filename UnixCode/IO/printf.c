/*
    #include <stdio.h>

    // 字符串中定义的格式的输出写入到 stdout
    int printf(const char *format, ...);
        return:
            - 成功返回输出到 stdout 的字符数
            - 失败返回负数

    // 字符串中定义的格式的输出写入到指定的文件流 stream
    int fprintf(FILE *stream, const char *format, ...);
        return:
            - 成功返回输出到文件流的字符数
            - 失败返回负数

    // 字符串中定义的格式的输出写入到指定的文件描述符 fd
    int dprintf(int fd, const char *format, ...);
        return:
            - 成功返回输出到文件描述符的字符数
            - 失败返回负数

    // 格式化输出字符写入 str，并在数组尾端加一个 null 字节，
    // 最多只会写入 size - 1 个字符
    // null 不在返回值中
    int sprintf(char *str, const char *format, ...);
        return:
            - 成功返回写到到字符串的字符数，不包含 null
            - 失败返回负数

    // sprintf 可能造成 str 指向的缓冲区溢出
    // size 指定缓冲区长度，最多只会写入 size - 1 个字符
    // 超过缓冲区尾端写的所有字符会被丢弃
    int snprintf(char *str, size_t size, const char *format, ...);
        return:
            - 成功返回根据格式字符串完全格式化后的字符数，不论实际上写入了多少字符
            - 失败返回负数

    #include <stdarg.h>

    int vprintf(const char *format, va_list ap);
    int vfprintf(FILE *stream, const char *format, va_list ap);
    int vdprintf(int fd, const char *format, va_list ap);
    int vsprintf(char *str, const char *format, va_list ap);
    int vsnprintf(char *str, size_t size, const char *format, va_list ap);
 */

#include <stdarg.h>

int main(int argc, char const *argv[]) {
    return 0;
}

