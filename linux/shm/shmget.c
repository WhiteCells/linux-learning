/*
    #include <sys/ipc.h>
    #include <sys/shm.h>

    int shmget(key_t key, size_t size, int shmflg);
        argument:
            - key:
            - size:
            - shmflg:

        return:
 */

#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    shmget();
    
    return 0;
}