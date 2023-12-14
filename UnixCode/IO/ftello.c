/*
    #include <stdio.h>

    // 与 fseek 区别: offset 参数类型为 off_t
    int fseeko(FILE *stream, off_t offset, int whence);
        argument:
            - stream: 文件流
            - offset: 偏移量
            - whence:
                - SEEK_CUR
                - SEEK_SET
                - SEEK_END
        return:
            - 成功返回 0
            - 失败返回 -1

    // 与 ftello 区别: 函数返回值类型 off_t
    off_t ftello(FILE *stream);
        return:
            - 成功返回当前文件位置
            - 失败返回 (off_t) -1
 */

#include <stdio.h>

int main(int argc, char const *argv[]) {
    return 0;
}
