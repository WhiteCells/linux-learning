/*
    #include <unistd.h>

    // 更改 pathname 文件的用户 ID 和组 ID
    int chown(const char *pathname, uid_t owner, gid_t group);
        argument:
            - pathname: 文件路径
            - owner: 用户 ID
            - grounp: 组 ID

        return:
            - 成功返回 0
            - 失败返回 -1，并设置 errno
    // 更改 fd 参数指向的打开文件的用户 ID 和组 ID
    int fchown(int fd, uid_t owner, gid_t group);

    // 直接对符号链接进行更改
    int lchown(const char *pathname, uid_t owner, gid_t group);

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <unistd.h>

    // 更改相对于已打开目录 fd 的文件 pathname 的用户 ID 和组 ID
    int fchownat(int dirfd, const char *pathname,
                 uid_t owner, gid_t group, int flags);
 */



#include <stdio.h>

int main() {
    return 0;
}