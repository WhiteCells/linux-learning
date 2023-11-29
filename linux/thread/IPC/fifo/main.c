#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char pathname[1024] = { 0 };
    char *ret = getcwd(pathname, sizeof(pathname));
    if (NULL == ret) {
        perror("getcwd");
        exit(0);
    }
    char r_program[1024] = { 0 };
    char w_program[1024] = { 0 };
    strcpy(r_program, pathname);
    strcpy(w_program, pathname);

    strcat(r_program, "/read");
    strcat(w_program, "/write");

    int ret2 = access("fifo1", F_OK);
    if (-1 == ret2) {
        printf("not exist fifo1, now create the named pipeline\n");
        ret2 = mkfifo("fifo1", 0755);
        if (-1 == ret2) {
            perror("mkfifo fifo1");
            exit(0);
        }
    }

    int s_pid = fork();

    if (0 == s_pid) {
        execl(w_program, "w_program", NULL);
    } else if (0 < s_pid) {
        execl(r_program, "r_program", NULL);
    } else {
        perror("fork");
        exit(0);
    }

    return 0;
}