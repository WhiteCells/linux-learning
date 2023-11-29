#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    /* 只写方式打开管道 */
    int fd = open("fifo1", O_WRONLY);
    if (-1 == fd) {
        perror("open fifo1");
        exit(0);
    }

    /* 写数据 */
    for (int i = 0; i < 10; ++i) {
        char buf[1024] = { 0 };
        sprintf(buf, "hello %d", i);
        printf("write: %s\n", buf);
        write(fd, buf, strlen(buf));
        sleep(1);
    }

    close(fd);
    return 0;
}