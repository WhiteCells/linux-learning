/*
    匿名映射
 */

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    // 创建匿名内存映射区
    int len = 4096;
    void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (MAP_FAILED == ptr) {
        perror("mmap");
        exit(0);
    }

    // 父子进程间通信
    pid_t s_pid = fork();

    if (0 == s_pid) {
        char buf[1024] = { 0 };
        fgets(buf, sizeof(buf), stdin);
        strcpy((char *)ptr, buf);
    } else if (0 < s_pid) {
        wait(NULL);
        printf("%s\n", (char *)ptr);
    } else if (-1 == s_pid) {
        perror("fork");
        munmap(ptr, len);
        exit(0);
    }

    // 释放映射区内存地址
    munmap(ptr, len);

    return 0;;
}