/*
    // 文件从磁盘映射到内存
    #include <sys/mman.h>

    void *mmap(void *addr, size_t length, int prot, int flags,
              int fd, off_t offset);
        argument:
            - addr: 映射的内存区地址
                - NULL: 由内核自动分配
                - 有效地址:
            - length: 映射的文件长度, 长度为 0 函数返回 NULL, 长度没有到分页大小默认为一个分页大小
                - 未指定: mmap 函数自动计算文件的大小
                - 0: mmap 函数返回 NULL
                - 文件大小不能被分页大小整除，那么余下的部分将被忽略，不会被映射到内存中
            - port: 映射区内存操作权限
                - PROT_READ: 读权限 (操作映射区必须要读权限)
                - PROT_WRITE: 写权限
                - PROT_EXEC: 可执行权限
                - PROT_NONE: 没有权限
            - flags: 标志位
                - MAP_SHARED: 映射内存区域可被多个进程共享 (默认 flags 参数)
                - MAP_PRIVATE: 不同步, 内存映射区的数据改变了,
                               原来文件不会修改, 会重新创建一个新文件 (copy on write)
            - fd: 文件描述符, 表示要映射的文件 (文件大小不能为 0, open 权限不能和 prot 冲突, open 权限要大于等于 prot 权限)
            - offset: 文件偏移量, 表示从文件哪个位置开始映射, 必须是 4k 的整数倍才能偏移成功
        return:
            - MAP_FAILED: ((void*) -1) 映射失败, set error
            - void*: 映射的内存地址首地址
 */

#include <sys/mman.h>

int main() {

    return 0;
}