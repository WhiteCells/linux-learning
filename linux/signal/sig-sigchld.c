/*
    SIGCHLD 信号产生的 3 个条件
        1. 子进程结束
        2. 子进程暂停
        3. 子进程由暂停到继续
 */

/* 使用 SIGCHLD 信号解决僵尸进程问题 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

void exitChildProcess(int num) {
    printf("caught signal: %d\n", num);
    // 回收子进程资源
    // 信号发送的很快, 信号不能累积
    while (1) {
        int ret = waitpid(-1, NULL, WNOHANG);
        if (0 < ret) {
            printf("child process pid: %d recycling\n", ret);
        } else if (0 == ret) {
            break;
        } else if (-1 == ret) {
            printf("child process recycling completed\n");
            break;
        }
    }
}

int main() {
    sigset_t sset;
    sigemptyset(&sset);
    sigaddset(&sset, SIGCHLD);
    sigprocmask(SIG_BLOCK, &sset, NULL);

    pid_t pid;
    for (int i = 0; i < 5; ++i) {
        pid = fork();
        if (0 == pid) {
            break;
        }
    }
    if (0 == pid) {
        printf("child process pid: %d\n", getpid());
    } else if (0 < pid) {
        // 捕捉子进程结束时发送的 SIGCHLD 信号
        // 考虑信号捕捉没有注册成功, 子进程已经结束了
        // 所以需要将阻塞信号集中的 SIGCHLD 设为阻塞
        struct sigaction act;
        act.sa_flags = 0;
        act.sa_handler = exitChildProcess;
        sigemptyset(&act.sa_mask);
        sigaction(SIGCHLD, &act, NULL);
        // 注册信号捕捉之后结束阻塞
        sigprocmask(SIG_UNBLOCK, &sset, NULL);
        while (1) {
            printf("parent process pid: %d\n", getpid());
            sleep(1);
        }
    } else if (-1 == pid) {
        perror("fork");
        exit(0);
    }
    return 0;
}