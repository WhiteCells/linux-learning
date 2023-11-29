/*
    // 将信号集中的所有标志位 置为 1
    #include <signal.h>

    int sigfillset(sigset_t *set);
        argument:
            - set: 传出参数, 需要操作的信号集

        return:
            - 0: success
            - -1: error, set errno

 */