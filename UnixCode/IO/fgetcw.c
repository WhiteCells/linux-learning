/*


 */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

int main(int argc, char const *argv[]) {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    write(fd, "测试", 6);
    char buf[1024] = {};
    lseek(fd, SEEK_SET, 0);
    read(fd, buf, sizeof buf);
    printf("%s\n", buf);
    return 0;
}
