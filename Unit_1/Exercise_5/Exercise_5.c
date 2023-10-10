#include <stdio.h>
#include <string.h>
#include <unistd.h>

void mouse_location(char* output_x, char* output_y) {
    FILE* cmd_output = popen("xdotool getmouselocation", "r");

    if (cmd_output == NULL) {
        printf("[Error] Don't open the command\n");
    }

    char file[256];
    fgets(file, sizeof(file), cmd_output);

    char* token;

    token = strtok(file, " ");
    strcpy(output_x, token);
    token = strtok(NULL, " ");
    strcpy(output_y, token);

    pclose(cmd_output);
}

int main() {
    char output_location_x[256];
    char output_location_y[256];
    int count;

    while (1) {
        mouse_location(output_location_x, output_location_y);

        printf("Mouse Location [%d]: %s %s\n", \
                count, \
                output_location_x, \
                output_location_y\
        );
        
        count++;
        
        usleep(30000);
    }
    
    return 0;
}