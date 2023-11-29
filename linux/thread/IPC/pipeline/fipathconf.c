/*
    #include <unistd.h>

    long fpathconf(int fd, int name);
        argument:
            - fd:
            - name:
                - _PC_LINK_MAX:
                - _PC_MAX_CANON:
                - _PC_MAX_INPUT:
                - _PC_NAME_MAX:
                - _PC_PATH_MAX:
                - _PC_PIPE_BUF:
                - _PC_CHOWN_RESTRICTED:
                - _PC_NO_TRUNC:
                - _PC_VDISABLE:
        return:
    long pathconf(const char *path, int name);

 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2];
    int ret = pipe(pipe_fd);

    if (-1 == ret) {
        perror("pipe");
        return -1;
    }

    /* 获取管道大小 */
    long pipe_buf_size = fpathconf(pipe_fd[0], _PC_PIPE_BUF);
    printf("pipe buf size: %ld\n", pipe_buf_size);
    return 0;
}

