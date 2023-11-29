#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    // ./main src.txt tar.txt
    if (3 != argc) {
        puts("Argument error");
        exit(1);
    }

    // 以读方式打开源文件
    int src_fd = open(argv[1], O_RDONLY);
    if (-1 == src_fd) {
        perror("open src");
        exit(0);
    }

    // 获取源文件的大小
    struct stat src_stat;
    if (-1 == fstat(src_fd, &src_stat)) {
        perror("fstat");
        close(src_fd);
        exit(0);
    }
    size_t src_file_len = src_stat.st_size;
    if (0 == src_file_len) {
        puts("src file empty");
        close(src_fd);
        exit(0);
    }

    // 以读写方式打开目标文件
    int tar_fd = open(argv[2], O_RDWR | O_CREAT, 0644);
    if (-1 == tar_fd) {
        perror("open tar");
        close(src_fd);
        exit(0);
    }

    // 设置目标文件的大小
    if (-1 == ftruncate(tar_fd, src_file_len)) {
        perror("ftruncate");
        close(tar_fd);
        close(src_fd);
        exit(0);
    }

    // 映射源文件
    void *src_file_ptr = mmap(NULL, src_file_len, PROT_READ, MAP_SHARED, src_fd, 0);
    if (MAP_FAILED == src_file_ptr) {
        perror("mmap src");
        close(tar_fd);
        close(src_fd);
        exit(0);
    }

    // 映射目标文件
    void *tar_file_ptr = mmap(NULL, src_file_len, PROT_READ | PROT_WRITE, MAP_SHARED, tar_fd, 0);
    if (MAP_FAILED == tar_file_ptr) {
        perror("mmap tar");
        munmap(src_file_ptr, src_file_len);
        close(tar_fd);
        close(src_fd);
        exit(0);
    }

    // 内存拷贝
    memcpy(tar_file_ptr, src_file_ptr, src_file_len);

    // 同步文件到磁盘
    msync(tar_file_ptr, src_file_len, MS_SYNC);

    // 释放映射
    munmap(tar_file_ptr, src_file_len);
    munmap(src_file_ptr, src_file_len);

    // 关闭文件描述符
    close(tar_fd);
    close(src_fd);

    return 0;
}