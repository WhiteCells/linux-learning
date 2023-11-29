#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **args) {
    /* 只写方式向 fifo2 中写 */
    int w_fd = open(args[2], O_WRONLY);
    if (-1 == w_fd) {
        perror("open");
        exit(0);
    }

    /* 只读的方式从 fifo1 中读 */
    int r_fd = open(args[1], O_RDONLY);
    if (-1 == r_fd) {
        perror("open");
        exit(0);
    }

    while (1) {
        printf("pid: %d enter message: ", getpid());
        char w_buf[1024] = { 0 };
        fgets(w_buf, sizeof(w_buf), stdin);
        write(w_fd, w_buf, strlen(w_buf));
        printf("pid: %d write: %s\n", getpid(), w_buf);

        char r_buf[1024] = { 0 };
        int r_len = read(r_fd, r_buf, sizeof(r_buf));
        if (0 == r_len) {
            puts("write close");
        } else if (-1 == r_len) {
            perror("read");
            exit(0);
        }
        printf("pid: %d read: %s", getpid(), r_buf);
    }

    close(w_fd);
    close(r_fd);
    return 0;
}