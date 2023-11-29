#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int s_pid = fork();

    if (0 < s_pid) {
        /* 父进程 */
        printf("this is parent process id: %d parent parent process id: %d\n", getpid(), getppid());
    }
    else if (0 == s_pid) {
        /* 子进程 */
        sleep(1); // 主进程结束，但是并不知道还有子进程还未执行，所以形成了再次显示前台
        printf("this is child process id: %d child parent process id: %d\n", getpid(), getppid());
    }
    return 0;
}
