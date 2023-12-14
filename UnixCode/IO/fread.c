/*
    #include <stdio.h>

    // 只能在读取同一操作系统上的数据，跨操作系统可能异常
    // 1. 同一 struct，在不同的操作系统或编译系统中，成员偏移量不同
    // 2. 存储多字节的整数和浮点数的二进制格式在不同的操作系统中可能不同
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
        argument:
            - ptr: 存放二进制数据对象的缓冲区
            - size: 单个二进制数据对象的字节数
            - nmemb: 二进制数据对象的数量
            - stream: 文件对象指针

        return:
            - 读或写的对象数

    size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                    FILE *stream);
 */