/*

 */

#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    实现 ps aux

    子进程执行 ps 命令
    将文件描述符重定向
 */
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
        close(pipe_fd[0]); // 关闭读端
        dup2(pipe_fd[1], STDOUT_FILENO); // 文件描述符重定向 STDOUT_FILENO -> pipe_fd[1] 
        int excelp_ret = execlp("ps", "ps", "aux", NULL); // 指定 ps aux 指令
        if (-1 == excelp_ret) {
            exit(-1);
        }
    }
    else if (0 < s_pid) {
        /* 父进程从管道读取数据 */
        close(pipe_fd[1]); // 关闭写端
        char buf[1024] = { 0 };
        int r_len = 0;
        while (0 < (r_len = read(pipe_fd[0], buf, sizeof(buf) - 1))) {
            printf("%s", buf);
            memset(buf, 0, sizeof(buf));
        }
        wait(NULL);
    }
    else {
        perror("fork");
    }
    return 0;
}
