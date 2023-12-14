/*
    #include <stdio.h>

    // 这些函数通常用于二进制文件
    // 在文本文件中，可能存在换行符转换
    // 字节位置可能不能准确反映字符的位置
    int fseek(FILE *stream, long offset, int whence);
        argument:
            - stream: 文件流
            - offset: 偏移量
            - whence: 
                - SEEK_SET
                - SEEK_CUR
                - SEEK_END
        return:
            - 成功返回 0
            - 失败返回 -1，设置 errno

    long ftell(FILE *stream);
        return:
            - 成功返回当前文件位置指示，从文件开始到当前位置的字节数
            - 失败返回 -1L，设置 errno

    // 将一个流设置到文件起始位置
    void rewind(FILE *stream);
 */

/*
你已经提供了fseek, ftell和rewind函数的基本定义和用法，我将为你提供更详细的解释：

    fseek：这个函数用于移动文件指针到指定的位置。fseek需要三个参数：文件流stream，偏移量offset，和起始点whence。whence可以是以下三个宏之一：
    SEEK_SET（从文件开头开始），SEEK_CUR（从当前位置开始），SEEK_END（从文件末尾开始）。如果操作成功，fseek返回0；否则，返回-1。

    ftell：这个函数返回给定流stream的当前文件位置指示器的值。这个值是从文件开始到当前位置的字节数。如果操作成功，ftell返回当前的文件位置；否则，返回-1L，并设置errno。

    rewind：这个函数将文件位置指示器设置到文件的开始。它等价于fseek(stream, 0L, SEEK_SET)，但是rewind不返回任何值。如果出现错误，可以通过ferror函数来检测。

这些函数通常用于二进制文件，因为在文本文件中，由于可能存在的换行符转换，字节位置可能不会准确反映字符的位置。
 */