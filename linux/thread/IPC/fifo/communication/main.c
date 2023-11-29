#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createFIFO(const char *pathname, mode_t mode);

void getPWD(char *path, const char *program);

/* ./main fifo1 fifo2 */
int main(int argc, char **args) {
    if (argc != 3) {
        puts("parameters error!");
        exit(0);
    }

    createFIFO(args[1], 0755);
    createFIFO(args[2], 0755);
    char fifo1_path[1024] = { 0 };
    char fifo2_path[1024] = { 0 };
    getPWD(fifo1_path, "program1");
    getPWD(fifo2_path, "program2");
    // printf("%s\n", fifo1_path);
    // printf("%s\n", fifo2_path);

    int s_pid = fork();

    if (0 == s_pid) {
        execl(fifo1_path, "program1", args[1], args[2], NULL);
    } else if (0 < s_pid) {
        execl(fifo2_path, "program2", args[1], args[2], NULL);
    } else {
        perror("fork");
        exit(0);
    }

    return 0;
}

void createFIFO(const char *pathname, mode_t mode) {
    int ret = access(pathname, F_OK);
    if (-1 == ret) {
        printf("%s not exist, now create %s\n", pathname, pathname);
        ret = mkfifo(pathname, mode);
        if (-1 == ret) {
            perror("mkfifo");
            exit(0);
        }
    }
}

void getPWD(char path[], const char *program) {
    char *ret = getcwd(path, 1024);
    if (NULL == ret) {
        perror("getcwd");
        exit(0);
    }
    sprintf(path, "%s/%s", path, program);
}