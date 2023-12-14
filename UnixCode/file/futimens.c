/*
    #include <fcntl.h> \* Definition of AT_* constants *\
    #include <sys/stat.h>

    int utimensat(int dirfd, const char *pathname,
                    const struct timespec times[2], int flags);
        argument:
            - dirfd: 目录文件描述符
            - pathname: 目录下的文件
            - times[2]: 日历时间，从 1970.1.1 00:00:00 至今的时间
                        一个包含两个 timespec 结构的数组，
                        分别代表访问时间 (times[0]) 和修改时间 (times[1])。
                        如果数组中的某个元素设置为 NULL，系统将使用当前时间。
                - time[0]: 访问时间
                - time[1]: 修改时间
            - flags: 控制函数行为的标志。常见的是 AT_SYMLINK_NOFOLLOW，它防止 utimensat 跟随符号链接。
        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno

    int futimens(int fd, const struct timespec times[2]);
 */

#include <fcntl.h>
#include <sys/stat.h>
