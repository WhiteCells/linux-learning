#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h> 
#include <sys/sysmacros.h>

int main() {
    struct stat buf1;
    if (stat("/dev/sdb", &buf1) < 0) {
        perror("Error getting information for /dev/sda1");
        exit(1);
    }

    printf("dev = %d/%d", major(buf1.st_dev), minor(buf1.st_dev));
    if (S_ISCHR(buf1.st_mode) || S_ISBLK(buf1.st_mode))
        printf("  (%s) rdev = %d/%d",
               (S_ISCHR(buf1.st_mode)) ? "character" : "block",
               major(buf1.st_rdev), minor(buf1.st_rdev));
    printf("\n");

    return 0;
}
