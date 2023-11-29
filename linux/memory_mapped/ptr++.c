#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("ft.txt", O_RDWR);
    int fd_sz = lseek(fd, 0, SEEK_END);
    void *ptr = mmap(NULL, fd_sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (NULL == ptr) {
        perror("mmap");
        exit(0);
    }
    close(fd);
    munmap(ptr, fd_sz);
    return 0;
}