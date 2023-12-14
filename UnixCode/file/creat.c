/*
creat() 函数是一个过时的系统调用，通常用于创建一个新文件或截断一个已存在文件，
并以只写方式打开文件。它是对 open() 函数的一种简化形式，
用于在创建文件时直接指定文件的权限位。

函数签名如下：

int creat(const char *pathname, mode_t mode);

    pathname：指定要创建的文件的路径名。
    mode：指定文件的权限位，通常使用 S_IRUSR、S_IWUSR、S_IRGRP、S_IROTH 等宏进行设置。

creat() 函数的行为类似于使用 open() 函数，带有以下标志：

    O_CREAT：如果文件不存在，则创建它。
    O_WRONLY：以只写方式打开文件。
    O_TRUNC：如果文件存在，将其截断为零长度。

实际上，creat() 函数可以等效地替换为以下 open() 函数调用：

int fd = open(pathname, O_CREAT | O_WRONLY | O_TRUNC, mode);

由于历史原因，creat() 函数仍然存在于一些系统中，但在现代编程中，通常推荐使用更灵活的 open() 函数来替代。
 */