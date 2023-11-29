#include <unistd.h>
#include <stdio.h>

int main() {
    int s_pid = fork();

    if (0 == s_pid) {
        printf("this is child process id: %d\n", getpid());
    }
    else if (0 < s_pid) {
        while (1) {
            printf("this is parent process id: %d\n", getpid());
            sleep(1);
        }
    }

    for (int i = 0; i < 10; ++i) {
        printf("this is parent process id: %d\n", getpid());
    }

    return 0;
}