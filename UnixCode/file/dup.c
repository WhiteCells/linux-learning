/*
    // 复制文件描述符
    #include <stdio.h>
    int dup(int lodfd);
        argument:
            - oldfd: 需要复制的文件描述符
        return:
            - 成功返回新的文件描述符返回新的文件描述符，
              新的文件描述符一定是当前可用的文件描述符中最小的数字
            - 失败返回 -1


    // dup2 系统调用执行与 dup 相同的任务，但它不使用编号最低的未使用文件描述符，
    // 而是使用 newfd 中指定的文件描述符编号。
    // 如果文件描述符 newfd 以前是打开的，那么它在被重用之前会被关闭。
    int dup2(int oldfd, int newfd);
        argument:
            - oldfd: 需要复制 oldfd 文件描述符
            - newfd: 复制到 newfd 文件描述符

        return:
            - 成功返回新的文件描述符返回新的文件描述符，
              新的文件描述符一定是当前可用的文件描述符中最小的数字
            - 失败返回 -1

        note:
            - 如果 oldfd 无效，复制失败，newfd 不会被关闭
            - 如果 oldfd 和 newfd 相等则什么都不会做，返回 newfd
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("../../test.c", O_RDWR);
    if (-1 == fd) {
        perror("open");
    }

    int cp_fd = dup(fd);
    printf("oldfd: %d\n", fd);
    printf("newfd: %d\n", cp_fd);

    int n_fd = dup2(cp_fd, fd); // 复制 cp_fd 文件描述符
                                // 返回 fd 文件描述符的编号
    printf("newfd: %d\n", n_fd);

    close(n_fd);
    close(cp_fd);
    close(fd);
    return 0;
}

