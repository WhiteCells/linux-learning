/*
    #include <stdlib.h>

    // 分配指定字节数的存储区，存储区的初始值不确定
    // malloc 返回内存所采用的字节对齐方式，宜于高效访问任何类型的数据结构
    // malloc 是基于 8 字节或 16 字节边界来分配内存
    // malloc(0) 要么返回 NULL，要么返回一块可被 free 释放的内存
    void *malloc(size_t size);

    // 为 指定数量 指定长度的对象 分配存储空间
    // 空间中每一位都初始化为 0
    void *calloc(size_t nmemb, size_t size);

    // 修改之前分配区的长度
    // 长度大于原长度时，函数调用前后可能是不同的存储
    // 所以调用前不应该有指针指向这段空间
    // 使用一个指针保存返回值，
    // 以传入参数为返回值，如果调用失败，则传回 NULL，
    // 原来的动态内存区就无法访问，从而发生内存泄漏
    void *realloc(void *ptr, size_t size);

    // 上述 3 个分配函数一定是适当对齐的，使其可用于任何数据对象

    // 释放动态分配空间
    // 将释放的内存增加到空闲内存列表中，供后续使用
    // 将释放的这块内存增加到空闲内存列表中，供后续的 malloc 再次使用
    // 不降低 program break 的位置
    // 1. 被释放的内存块通常位于堆的中间，而非堆的顶部
    // 2. 最大限度减少 sbrk 的调用次数
    // 3. 降低 program break 不会对分配大量内存的程序有多少帮助
    void free(void *ptr);
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    /* malloc(0) */
    // void *ptr = malloc(0);
    // if (ptr) {
    //     puts("this ptr not null");
    //     printf("%p\n", ptr);
    //     free(ptr);
    // } else {
    //     puts("this ptr is null");
    // }

    /* calloc */
    // int *ptr = (int *)calloc(4, sizeof(int));
    // for (int i = 0; i < 4; ++i) {
    //     printf("%d", *(ptr + i));
    // }

    int fd = open("../../a.out", O_RDONLY);
    return 0;
}