#include <stdio.h>
#include <string.h>

int main() {
    char buf[1024] = { 0 };
    fgets(buf, sizeof(buf), stdin); // 会读取换行符和空格
    printf("%s", buf);
    printf("%lu\n", strlen(buf) - 1);

    memset(buf, 0, sizeof(buf));
    scanf("%s", buf); // 不会读取换行符和空格之后的内容
    printf("%s\n", buf);
    printf("%lu\n", strlen(buf));

    memset(buf, 0, sizeof(buf));
    strcpy(buf, "hello");
    printf("%lu\n", strlen(buf));

    return 0;
}