/*
    #include <stdio.h>

    // 是一个函数，可以取地址，允许作为参数传递
    int fgetc(FILE *stream);
        argument:
            - stream:

        return:
            - 成功返回下一个字符 unsigned char 转换为 int
              返回 int 是为 EOF 常量设计
            - 到达文件结尾或失败返回 EOF（-1）

    // 可通过宏定义实现，不能作为参数传递
    // 参数不应该是有副作用的表达式，因为它可能被计算多次
    int getc(FILE *stream);

    // 等价于 getc(stdin)
    int getchar(void);

 */