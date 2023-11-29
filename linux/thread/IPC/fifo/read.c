#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    /* 只读方式打开管道 */
    int fd = open("fifo1", O_RDONLY);
    if (-1 == fd) {
        perror("open fifo1");
        exit(0);
    }

    while (1) {
        char buf[1024] = { 0 };
        int len = read(fd, buf, sizeof(buf));
        if (0 == len) {
            printf("write close");
            break;
        } else if (-1 == len) {
            perror("read");
            break;
        }
        printf("read: %s\n", buf);
        sleep(1);
    }

    close(fd);
    return 0;
}