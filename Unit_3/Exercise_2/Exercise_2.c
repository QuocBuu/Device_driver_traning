#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <folder_path>\n", argv[0]);
        return 1;
    }

    char *folderPath = argv[1];

    DIR *dir;
    struct dirent *entry;

    dir = opendir(folderPath);
    if (dir == NULL) {
        printf("Could not open the directory.\n");
        return 1;
    }

   while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the file path
        char filePath[257];  // Increase buffer size to accommodate the longest possible file path
        snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, entry->d_name);

        // Get file information
        struct stat fileStat;
        if (stat(filePath, &fileStat) < 0) {
            printf("Could not get file information.\n");
            continue;
        }

        // Print file information
        printf("Name: %s\n", entry->d_name);
        printf("Size: %lld bytes\n", (long long)fileStat.st_size);

        // Modified time
        char modifiedTime[20];
        strftime(modifiedTime, sizeof(modifiedTime), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
        printf("Modified time: %s\n", modifiedTime);

        printf("----------------------\n");
    }

    // Close the directory
    closedir(dir);

    return 0;
}