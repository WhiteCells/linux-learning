/*
    // 发送 SIGABRT 信号给当前进程, 杀死当前进程
    #include <stdlib.h>

    void abort(void);
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
    abort();
    puts("eee");
    return 0;
}