#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Xin chào";
    char str2[] = "Việt Nam";

    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Hai chuỗi bằng nhau.\n");
    } else if (result < 0) {
        printf("str1 nhỏ hơn str2.\n");
    } else {
        printf("str1 lớn hơn str2.\n");
    }

    return 0;
}