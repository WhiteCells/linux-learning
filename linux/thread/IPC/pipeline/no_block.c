/*
    设置管道非阻塞
    int flag = fcntl(df[0], F_GETFL); // 获取原来的 flag
    flags |= O_NONBLOCK
    fcntl(fd[0], F_SETFL, flags);
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    int ret = pipe(pipe_fd);

    if (-1 == ret) {
        perror("pipe");
        return -1;
    }

    pid_t s_pid = fork();
    if (0 == s_pid) {
        /* 子进程向管道写入数据 */
        printf("this is child process, pid: %d\n", getpid());
        close(pipe_fd[0]); // 关闭读端
        char buf[1024] = { 0 };
        char *str = "I am child";
        while (1) {
            write(pipe_fd[1], str, strlen(str));
            sleep(1);
        }
    } else if (0 < s_pid) {
        /* 父进程从管道读取数据 */
        printf("this is parent process, pid : %d\n", getpid());
        close(pipe_fd[1]); // 关闭写端
        /* 设置非阻塞 */
        int flags = fcntl(pipe_fd[0], F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(pipe_fd[0], F_SETFL, flags);

        char buf[1024] = { 0 };
        while (1) {
            int len = read(pipe_fd[0], buf, sizeof(buf));
            printf("parent recv: %s, pid: %d\n", buf, getpid());
            printf("read len: %d\n", len);
            memset(buf, 0, sizeof(buf));
            sleep(1);
        }
    } else {
        perror("fork");
    }
    return 0;
}