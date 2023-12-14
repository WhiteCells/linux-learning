/*
    #include <stdio.h>

    int fflush(FILE *stream);
        argument:
            - stream: 打开文件对象的指针

        return: 
            - 成功返回 0
            - 失败返回 EOF
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // printf("test");
    perror("test");
    while (1) {
        // sleep(3);
        // fflush(stdout);
    }

    return 0;
}
