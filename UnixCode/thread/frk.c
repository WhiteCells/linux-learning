/*
    #include <unistd.h>

    // 将 program break 设置为参数指定的位置
    // 虚拟内存以页为单位进行分配
    // 所以 end_data_segment 实际会四舍五入到下一个内存页的边界处
    // 试图将 end_data_segment 设置为一个低于其初始值（&end）的位置时，可能导致无法预知的行为
    int brk(void *addr);
        argument:
            - addr: 指定的地址
        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno，ENOMEM

    void *sbrk(intptr_t increment);
        argument:
            - increment: intptr_t 32位 int，64位 long int
                         在原有地址上增加参数指定的大小
        return:
            - 成功返回之前 program break 地址
            - 失败返回 (void*) -1，设置 errno，ENOMEN
 */

#include <unistd.h>
#include <stdio.h>

int main() {
    printf("当前: %p\n", sbrk(0));
    void *ptr = sbrk(-1);
    printf("当前: %p\n", sbrk(0));
    return 0;
}