/*
    #include <sys/types.h>
    #include <dirent.h>

    // 打开 name 路径目录
    DIR *opendir(const char *name);
        argument:
            - name: 需要打开的目录路径

        return:
            - 成功返回指向目录的指针流
            - 失败返回 NULL，设置 errno

    // 打开 fd 表示的目录
    DIR *fdopendir(int fd);
        argument:
            - fd: 需要打开目录的文件描述符

    struct dirent {
        ino_t          d_ino;       // 目录进入点 inode
        off_t          d_off;       // 目录文件开头至目录文件进入点的位移
        unsigned short d_reclen;    // d_name 的长度，不包含 NULL 字符
        unsigned char  d_type;      // d_name 文件类型
                                    // DT_BLK - 块设备
                                    // DT_CHR - 字符设备
                                    // DT_DIR - 目录
                                    // DT_LNK - 软连接
                                    // DT_REG - 普通文件
                                    // DT_SOCK - 套接字
                                    // DT_UNKNOWN - 未知
        char           d_name[256]; // null-terminated（以 null 结尾的）文件名
    };
 */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    
}