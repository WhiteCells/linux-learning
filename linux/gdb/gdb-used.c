#include <stdio.h>
#include <stdlib.h>

int test(int a);

/*
// 源文件编译成包含调试信息的可执行文件 test
gcc -g gdb-used.c -o test

// 进入 gdb
gdb test

// b 30 在当前源文件下 30 行打断点
// i b 查看断点信息
// del 1 删除 1 断点
// run 开始调试
// c 下一个断点
// n 下一条语句
 */
int main(int argc, char* argv[]) {
    int a, b;
    printf("argc = %d\n", argc);
    if (argc < 3) { // 参数的个数 < 3
        a = 10;
        b = 30;
    }
    else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);

    for (int i = 0; i < a; ++i) {
        printf("i = %d\n", i);
        int res = test(i);
        printf("res value: %d\n", res);
    }
    printf("THE END\n");
    return 0;
}

int test(int a) {
    int num = 0;
    for (int i = 0; i < a; ++i) {
        num += i;
    }
    return num;
}
