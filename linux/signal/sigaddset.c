/*
    // 设置信号集中的某一个信号对应的标志位为 1, 表示阻塞这个信号
    #include <signal.h>

    int sigaddset(sigset_t *set, int signum);
        argument:
            - set: 传出参数, 需要操作的信号集
            - signum: 对应信号编号的标志位置 1 表示阻塞

        return:
            - 0: success
            - -1: error, set errno
 */
