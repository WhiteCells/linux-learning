/*
    // 读文件
    #include <unistd.h>

    ssize_t read(int fd, const void *buf, size_t count);
        arguments:
            - fd: 打开的文件的文件描述符
            - buf: 传出参数，存放读取内容的缓冲区的地址
            - count: 期望读到的字节数
        return:
            - error:
                - -1: On error, -1 is returned, and errno is set appropriately，设置 perror
            - success:
                - > 0: 返回实际的读取到的字节数
                - = 0: 已经读取到文件末尾
 */

// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// 
// int main() {
//     int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
// 
//     int cp_fd = open("test1.txt", O_RDWR | O_CREAT, 0644);
//     char buf[1024] = {};
//     int byte_read = 0;
//     while ((byte_read = read(fd, buf, sizeof(buf))) > 0) {
//         printf("%s\n", buf);
//         write(cp_fd, buf, byte_read);
//         memset(buf, 0, sizeof(buf));
//     }
// 
//     close(cp_fd);
//     close(fd);
//     return 0;
// }

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);

    char buf[1024] = {};
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buf, sizeof(buf))) > 0) {
        // fwrite(buf, 1, bytesRead, stdout);  // 直接写入标准输出
        printf("%s\n", buf);
        memset(buf, 0, sizeof(buf));
    }

    close(fd);
    return 0;
}
