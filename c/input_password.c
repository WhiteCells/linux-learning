/*
关闭终端的回显功能 (密码输入)
在终端输入实际是通过 stdin 文件输入
每个进程在开启时都会打开 3 个文件，stdin -> 0, stdout -> 1, stderr ->2
关闭终端显示需要取消 ECHO 属性
 */

#include <stdio.h>
#include <termios.h>

/* 关闭终端回显功能 */
void DeleteEchoFeature(struct termios* term) {
    term->c_lflag &= ~ECHO;
    tcsetattr(0, TCSAFLUSH, term);
    /*
    TCSANOW：立即进行修改，并且不等待数据发送或接收完成。这意味着在调用 tcsetattr() 后，可能仍然有未处理的输入或输出数据。适用于需要立即生效的属性修改。
    TCSADRAIN：等待所有输出完成后进行修改，在修改前如果有未处理的数据仍然会被处理。适用于需要确保输出完成后再修改属性的情况。
    TCSAFLUSH：等待所有输出完成后进行修改，并且清空输入缓冲区中的所有未读取数据。适用于需要确保输入输出都已完成并清空缓冲区的情况。
     */
}

/* 恢复终端回显功能 */
void RecoveryEchoFeature(struct termios* term) {
    term->c_lflag |= ECHO;
    tcsetattr(0, TCSAFLUSH, term);
}

int main() {
    struct termios term;
    tcgetattr(0, &term);

    char account_name[128];
    printf("enter username: ");
    scanf("%s", account_name);

    char password[100];
    printf("enter password: ");

    /* 输入密码前关闭终端回显 */
    DeleteEchoFeature(&term);
    scanf("%s", password);

    /* 输入结束后恢复终端回显 */
    RecoveryEchoFeature(&term);

    // test
    printf("\npassword: %s\n", password);

    return 0;
}