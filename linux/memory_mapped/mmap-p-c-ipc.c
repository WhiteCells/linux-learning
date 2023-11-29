#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

/*
使用内存映射完成进程间通信

关系进程
    在没有子进程时，通过唯一的父进程，先创建内存映射区
    有了内存映射区，创建子进程
    父子进程共享创建的内存映射区

无关系进程
    准备一个大小非 0 的磁盘文件
    a 进程通过磁盘文件创建内存映射区，得到一个操作这块内存的指针
    b 进程通过磁盘文件创建内存映射区，得到一个操作这块内存的指针
 */

int main() {
    // 以读写权限打开文件
    int fd = open("ft.txt", O_RDWR);

    // 获取文件大小
    int fd_sz = lseek(fd, 0, SEEK_END);

    // 文件大小为空需要更改文件大小
    if (0 == fd_sz) {
        int ret = truncate("ft.txt", 1);
        if (-1 == ret) {
            perror("truncate");
            close(fd);
            exit(0);
        }
    }

    fd_sz = lseek(fd, 0, SEEK_END);

    // 磁盘文件映射到内存区, 返回其在内存映射区地址的首地址
    void *ptr = mmap(NULL, fd_sz, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    // 检查是否映射成功
    if (MAP_FAILED == ptr) {
        perror("mmap");
        close(fd);
        exit(0);
    }

    // 创建子进程
    pid_t s_pid = fork();

    if (0 == s_pid) {
        char buf[128] = { 0 };
        printf("write data: ");
        fgets(buf, sizeof(buf), stdin);
        strcpy((char *)ptr, buf);
        // strcpy((char *)ptr, "i am parent process");
    } else if (0 < s_pid) {
        wait(NULL);
        char buf[64] = { 0 };
        strcpy(buf, (char *)ptr);
        printf("read data: %s\n", buf);
    } else if (-1 == s_pid) {
        perror("fork");
        close(fd);
        exit(0);
    }

    // 关闭内存映射区地址
    munmap(ptr, fd_sz);

    close(fd);
    return 0;
}

