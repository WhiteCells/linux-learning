/*
    #include <stdio.h>

    // scanf 族用于分析输入字符串，将字符串序列转换成指定类型的变量
    // 除了转换说明和空白字符以外，格式字符串中的其他字符必须与输入匹配
    // 如有一个字符不匹配，则停止后续处理，不再读输入的其余部分
    int scanf(const char *format, ...);
        return:
            - 成功返回赋值的输入项数
            - 失败，输入错误或在任意转换前达到文件尾端，返回 EOF
    int fscanf(FILE *stream, const char *format, ...);
    int sscanf(const char *str, const char *format, ...);
 */


#include <stdio.h>
#include <wchar.h>
#include <string.h>

int main() {
    int num1 = 15;
    int num2 = -15;
    printf("%#x\n", num1);
    printf("%#o\n", num1);
    printf("%.5d\n", num2);
    printf("%i\n", num2);
    long a = 10;
    char c = L'a';
    const wchar_t *s = L"测试";
    const char *s2 = "";
    printf("%ld\n", strlen((const char *)s));
    printf("%c\n", c);
    printf("%li\n", a);
    int qq = 10;
    scanf("%*d", &qq);
    printf("%d\n", qq);
    const char *str = "test";
    printf("%s\n", str);
    return 0;
}
