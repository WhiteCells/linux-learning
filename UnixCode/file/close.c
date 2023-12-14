/*
    // 关闭一个文件描述符，使文件描述符不再指向任何文件
    #include <unistd.h>

    int close(int fd);
        argument:
            - fd: 需要关闭的文件描述符

        return:
            - 成功返回 0
            - 失败返回 -1 并设置 errno
 */