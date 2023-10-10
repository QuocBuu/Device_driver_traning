#include <stdio.h>
#include <stdlib.h>

int main() {
	system("echo -n 'Call command line echo in c'");
	printf("\n");
	system("ls /dev/tty*");
	return 0;
}
