/*
    使用内存映射实现文件拷贝

    1. 对源文件进行内存映射
    2. 创建一个新文件
    3. 将新文件的数据映射到内存
    4，通过内存拷贝源文件的内存拷贝到新文件的内存
    5. 释放资源
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // ./main src_file.txt tar_file.txt
    if (3 != argc) {
        puts("arrument error");
        exit(0);
    }

    // 检查源文件是否存在
    if (-1 == access(argv[1], F_OK)) {
        perror("open src");
        exit(0);
    }
    int src_fd = open(argv[1], O_RDONLY);

    // 检查目标文件是否存在
    // 不存在则以读写的权限创建文件
    // 存在且目标文件非空则清空目标文件
    int tar_fd = 0;
    if (-1 == access(argv[2], F_OK)) {
        tar_fd = open(argv[2], O_RDWR | O_CREAT, 0755);
    } else {
        tar_fd = open(argv[2], O_RDWR);
    }

    // 获取两文件长度并将映射到内存
    size_t src_file_len = lseek(src_fd, 0, SEEK_END);
    if (-1 == src_file_len) {
        puts("src file empty");
        exit(0);
    }
    printf("src_file_len: %lu\n", src_file_len);

    char buf[128] = { 0 };
    if (NULL == getcwd(buf, 128)) {
        perror("getcwd");
        exit(0);
    }
    char path[1024] = { 0 };
    sprintf(path, "%s/%s", buf, argv[2]);
    if (-1 == truncate(path, src_file_len)) {
        perror("truncate");
        exit(0);
    }
    size_t tar_file_len = lseek(tar_fd, 0, SEEK_END);
    printf("tar_file_len: %lu\n", tar_file_len);
    
    void *src_file_ptr = mmap(NULL, src_file_len, PROT_READ, MAP_SHARED, src_fd, 0);
    void *tar_file_ptr = mmap(NULL, tar_file_len, PROT_READ | PROT_WRITE, MAP_SHARED, tar_fd, 0);

    memcpy(tar_file_ptr, src_file_ptr, src_file_len);

    // 释放文件映射地址
    munmap(src_file_ptr, src_file_len);
    munmap(tar_file_ptr, tar_file_len);

    return 0;
}