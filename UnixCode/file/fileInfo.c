#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/*
模拟 ls
./a.out file
-rwxr-xr-x 1 eorys eorys 12 Aug 24 08:25 ../word.txt
 */
int main(int argc, char const *argv[]) {
    if (2 != argc) {
        printf("parameter error: ");
        if (2 < argc) {
            printf("too many parament, ");
            for (int i = 2; i < argc; ++i) {
                printf("%s ", argv[i]);
            }
        }
        else {
            printf("too few parameters");
        }
        printf("\nplease use the following format: %s filename\n", argv[0]);
        return -1;
    }

    struct stat file_stat;
    int ret = stat(argv[1], &file_stat);
    if (-1 == ret) {
        perror(argv[1]);
        exit(0);
    }

    char file_mode[11] = { 0 };

    /* 1.文件权限 */
    // 文件类型
    switch (file_stat.st_mode & S_IFMT) {
        case S_IFSOCK: /* 套接字 */
            file_mode[0] = 's';
            break;
        case S_IFLNK: /* 软连接 */
            file_mode[0] = 'l';
            break;
        case S_IFREG: /* 普通文件 */
            file_mode[0] = '-';
            break;
        case S_IFBLK: /* 块设备 */
            file_mode[0] = 'b';
            break;
        case S_IFDIR: /* 目录 */
            file_mode[0] = 'd';
            break;
        case S_IFCHR: /* 字符设备 */
            file_mode[0] = 'c';
            break;
        case S_IFIFO: /* 管道 */
            file_mode[0] = 'p';
            break;
        default:
            break;
    }
    // User
    file_mode[1] = (file_stat.st_mode & S_IRUSR) ? 'r' : '-';
    file_mode[2] = (file_stat.st_mode & S_IWUSR) ? 'w' : '-';
    file_mode[3] = (file_stat.st_mode & S_IXUSR) ? 'x' : '-';
    // Group
    file_mode[4] = (file_stat.st_mode & S_IRGRP) ? 'r' : '-';
    file_mode[5] = (file_stat.st_mode & S_IWGRP) ? 'w' : '-';
    file_mode[6] = (file_stat.st_mode & S_IXGRP) ? 'x' : '-';
    // Others
    file_mode[7] = (file_stat.st_mode & S_IROTH) ? 'r' : '-';
    file_mode[8] = (file_stat.st_mode & S_IWOTH) ? 'w' : '-';
    file_mode[9] = (file_stat.st_mode & S_IXOTH) ? 'x' : '-';

    file_mode[10] = '\0';

    /* 2.硬链接数 */
    unsigned long file_nlink = file_stat.st_nlink;

    /* 3.所有者 */
    struct passwd* pw_user = getpwuid(file_stat.st_uid); // pwd.h
    char* file_user = pw_user->pw_name;

    /* 4.所属组 */
    struct group* pw_group = getgrgid(file_stat.st_gid); // grp.h
    char* file_group = pw_group->gr_name;

    /* 5.文件大小 */
    long file_size = file_stat.st_size;

    /* 6.最后修改时间 */
    long time_stamp = file_stat.st_mtime;
    char* time = ctime(&time_stamp); // 带换行

    char file_m_time[512] = { 0 };
    strncpy(file_m_time, time, strlen(time) - 1); // 去掉 '\n'

    /* 7.文件名 */
    const char* file_name = argv[1];

    char buf[1024] = { 0 };
    sprintf(buf, "%s %ld %s %s %ld %s %s",
            file_mode, file_nlink, file_user, file_group,
            file_size, file_m_time, file_name);
    printf("%s\n", buf);

    return 0;
}