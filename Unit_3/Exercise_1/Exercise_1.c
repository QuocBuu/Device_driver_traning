#include <stdio.h>

int main() {
    char *path = "/home/buu/Workspace/Device_driver_traning/Unit_3/Exercise_1/file_text.txt";  // Đường dẫn đến địa chỉ bất kỳ trong ổ đĩa

    // Tạo và mở tệp tin
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Không thể mở tệp tin.\n");
        return 1;
    }

    // Ghi dữ liệu vào tệp tin
    fprintf(file, "Name: Phan Quoc Buu\nAge: 22\n");

    // Đóng tệp tin
    fclose(file);

    // Mở tệp tin và đọc nội dung
    file = fopen(path, "r");
    if (file == NULL) {
        printf("Không thể mở tệp tin.\n");
        return 1;
    }

    // Đọc nội dung từ tệp tin
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Đóng tệp tin
    fclose(file);

    return 0;
}