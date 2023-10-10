#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int PID;
	printf("Enter the Ip of Process: ");
	scanf("%d",&PID);

	char command[100];
	sprintf(command, "ps -o cmd fp %d | sed 's/CMD//' | tr -d '\n'> output.txt", PID);

	system(command);

	FILE* file = fopen("output.txt", "r");
	if(file == NULL) {
		printf("Error can't open 'output.txt'\n");
	}

	char line[100];
	int check;
	
	while(fgets(line, 100, file) != NULL) {
		printf("Name Process is: %s\n", line);
		check++;
	}
	if(check == 896) {
		printf("IP error!\n");
	}
	printf("%d",check);

	fclose(file);

	return 0;
}


