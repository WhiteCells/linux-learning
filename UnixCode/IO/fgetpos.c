/*
    #include <stdio.h>

    // 由 ISO C 标准引入
    // 这两个函数通常处理大文件，fpos_t 类型通常能存储比 long 更大的值
    // 获取当前文件指针位置
    int fgetpos(FILE *stream, fpos_t *pos);
        argument:
            - stream: 文件流
            - pos: 传出参数，fpos_t 类型指针
        return:
            - 成功返回 0
            - 失败返回非 0

    // 设置文件指针位置
    int fsetpos(FILE *stream, const fpos_t *pos);
 */

/*
`fgetpos` 和 `fsetpos` 是两个用于处理文件位置的函数。它们的作用类似于 `ftell` 和 `fseek`，但是它们使用 `fpos_t` 类型的参数，这使得它们在处理大文件时更加灵活和精确。

1. `fgetpos`：这个函数用于获取当前文件指针的位置。它需要两个参数：文件流 `stream` 和一个 `fpos_t` 类型的指针 `pos`。
`fgetpos` 将当前文件指针的位置存储在 `pos` 指向的 `fpos_t` 类型的变量中。如果操作成功，`fgetpos` 返回 0；否则，返回非零值。

2. `fsetpos`：这个函数用于设置文件指针的位置。它需要两个参数：文件流 `stream` 和一个 `fpos_t` 类型的常量指针 `pos`。
`fsetpos` 将文件指针移动到 `pos` 指向的 `fpos_t` 类型的变量所表示的位置。如果操作成功，`fsetpos` 返回 0；否则，返回非零值。

这两个函数通常用于处理大文件，因为 `fpos_t` 类型的变量通常能够存储比 `long` 类型更大的值。
 */

#include <stdio.h>

int main() {
    FILE *file;
    fpos_t position;

    file = fopen("test.txt", "w");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }

    fputs("Hello, World!", file);

    // 获取当前位置
    fgetpos(file, &position);
    printf("Position after writing: %lld\n", position);

    // 写入更多数据
    fputs(" More text here.", file);

    // 重置到之前的位置
    fsetpos(file, &position);

    // 写入更多数据
    fputs(" Overwritten.", file);

    fclose(file);

    return 0;
}