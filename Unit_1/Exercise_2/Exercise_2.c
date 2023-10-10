#include <stdio.h>

int main() {
	FILE *file;

	file = fopen("file_text.txt", "r");
	/* r": Mở file để đọc. Nếu file không tồn tại thì trả về NULL.

	"w": Mở file để ghi (write). Nếu file không tồn tại thì tạo mới. Nếu có sẵn thì xóa nội dung cũ.

	"a": Mở file để ghi ở cuối. Nếu file không tồn tại thì tạo mới.

	"r+": Mở file để đọc và ghi */
	
	if (file == NULL) {
		printf("Error opening file!\n");
	}

	char line[100];

	while(fgets(line, 100, file) != NULL) {
		printf("%s", line);
	}

	fclose(file);

	return 0;
}
