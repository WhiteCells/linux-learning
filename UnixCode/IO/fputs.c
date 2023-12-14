/*
    #include <stdio.h>

    // 以 null 终止的字符串写到流中，null 不写出
    // 不自动添加换行符
    int fputs(const char *s, FILE *stream);
        argument:
            - s: 待写入字符串
            - stream: 文件对象指针

        return:
            - 成功返回非负值
            - 失败返回 EOF

    // 以 null 终止的字符串写到流中，null 不写出
    // 自动添加换行符，换行符也写到标准输出中 
    int puts(const char *s);
 */

#include <stdio.h>

int main() {
    puts("test");
    fputs("test", stdout);
    return 0;
}