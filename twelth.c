#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "path.txt";

    // Open the file for reading and writing
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Use fcntl to get the file access mode
    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    if (flags & O_RDONLY) {
        printf("File is opened in read-only mode\n");
    }
    if (flags & O_WRONLY) {
        printf("File is opened in write-only mode\n");
    }
    if (flags & O_RDWR) {
        printf("File is opened in read-write mode\n");
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

