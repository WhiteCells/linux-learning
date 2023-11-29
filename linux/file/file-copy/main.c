#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    /* 打开文件 copy.txt */
    int source_file = open("file1.txt", O_RDONLY);
    if (-1 == source_file) {
        perror("open copy.txt");
        return -1;
    }

    /* 创建一个新文件 copy-tmp.txt */
    int copy_file = open("file1-copy.txt", O_WRONLY | O_CREAT, 0664);
    if (-1 == copy_file) {
        perror("open copy_file.txt");
        return -1;
    }

    /* 读 copy.txt 并向 buf 写入 */
    char buf[1024] = { 0 };
    int len = 0;
    while ((len = read(source_file, buf, sizeof(buf))) > 0) {
        write(copy_file, buf, len);
    }

    /* 关闭两个文件 */
    close(source_file);
    close(copy_file);
    return 0;
}