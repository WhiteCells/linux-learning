#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **args) {
    /* 只读方式打开 fifo2 */
    int r_fd = open(args[2], O_RDONLY);
    if (-1 == r_fd) {
        perror("open");
        exit(0);
    }

    /* 只写方式打开 fifo1 */
    int w_fd = open(args[1], O_WRONLY);
    if (-1 == w_fd) {
        perror("open");
        exit(0);
    }

    while (1) {
        char r_buf[1024] = { 0 };
        int len = read(r_fd, r_buf, sizeof(r_buf));
        if (0 == len) {
            puts("write close");
            exit(0);
        } else if (-1 == len) {
            perror("read");
            exit(0);
        }
        printf("pid: %d read: %s\n", getpid(), r_buf);

        printf("pid: %d 输入信息: ", getpid());
        char w_buf[1024] = { 0 };
        fgets(w_buf, sizeof(w_buf), stdin);
        write(w_fd, w_buf, strlen(w_buf));
        printf("pid: %d write: %s\n", getpid(), w_buf);
    }

    return 0;
}