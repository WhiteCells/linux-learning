/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    // 获取文件状态
    int stat(const char *pathname, struct stat *statbuf);
        argument:
            - pathname: 文件路径
            - statbuf: 传出参数，结构体变量，保存获取到的文件的信息

        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno

    int fstat(int fd, struct stat *statbuf);
        argument:
            - fd: 文件描述符
            - statbuf: 传出参数，结构体变量，保存获取到的文件的信息

    int lstat(const char *pathname, struct stat *statbuf);
        argument:
            - pathname: 当 pathname 为一个符号链接时，返回符号链接的有关信息
            - statbuf: 传出参数，结构体变量，保存获取到的文件的信息

    #include <fcntl.h>           \* Definition of AT_* constants *\
    #include <sys/stat.h>

    // 获取相对于打开目录 fd 的文件 pathname 的统计信息
    int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);
        argument:
            - dirfd: 打开目录
            - pathname: 如果是一个绝对路径，参数`fd`就会被忽略
            - statbuf: 传出参数，结构体变量，保存获取到的文件的信息
            - flags: 设置了 AT_SYMLINK_NOFOLLOW 标志：如果文件是符号链接则直接获取符号链接的信息
                     如果文件是符号链接，会顺着链接获取链接文件的信息
    note:
        struct stat {
                dev_t     st_dev;           // 文件的设备编号
                ino_t     st_ino;           // 文件的 inode 号
                mode_t    st_mode;          // 文件的类型和存储的权限
                nlink_t   st_nlink;         // 连到该文件的硬链接数目
                uid_t     st_uid;           // 用户 ID
                gid_t     st_gid;           // 组 ID
                dev_t     st_rdev;          // 设备文件的设备编号
                off_t     st_size;          // 文件字节数(文件大小)
                blksize_t st_blksize;       // 块大小
                blkcnt_t  st_blocks;        // 块数
                struct timespec st_atim;    // 最后一次访问时间(time_t)
                struct timespec st_mtim;    // 最后一次修改时间(time_t)
                struct timespec st_ctim;    // 最后一次(属性)改变时间(time_t)
        };
 */


