/*
    #include <stdio.h>

    // 若压入一个序列，压入和读取是反序的，后进先出
    // 不能压入 EOF
    // 将字符压入缓冲区
    int ungetc(int c, FILE *stream);
        argument:
            - c: 待压入字符
            - stream: 打开的文件对象指针

        return:
            - 成功返回 c
            - 失败返回 EOF
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = getchar();

    if (c != EOF) {
        ungetc(c, stdin);  // 将字符压回到输入流中

        printf("The next character read will be: %c\n", getchar());  // 再次读取字符
    }
    return 0;
}
