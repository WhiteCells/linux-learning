/*
    #include <stdio.h>

    // 读到换行符为止，不超过 n - 1 个字符
    // s 缓冲区以 null 结尾
    // 如果一行包含换行符超过 n - 1 个字节，则只返回一个不完整的行
    // 下一次调用 fgets 继续读该行
    char *fgets(char *s, int size, FILE *stream);
        argument:
            - s: 存放读取到的字符的缓冲区地址
            - size: 缓冲区长度
            - stream: 文件对象指针
        return:
            - 成功返回 s
            - 到达文件尾端或失败返回 NULL

    // 无法指定缓冲区长度，可能造成缓冲区溢出漏洞
    // 不将换行符存入缓冲区中
    char *gets(char *s);
 */

#include <stdio.h>

int main(int argc, char const *argv[]) {
    FILE *fptr = fopen("test.txt", "r+");
    fseek(fptr, 0, SEEK_SET);
    fputs("test", fptr);
    char buf[128] = {};
    fseek(fptr, 0, SEEK_SET);
    fgets(buf, sizeof buf, fptr);
    printf("%s", buf);
    fclose(fptr);
    return 0;
}
