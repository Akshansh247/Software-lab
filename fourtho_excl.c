#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char* filename = "something.txt";
    int fd = open(filename, O_RDWR | O_EXCL);

    if (fd == -1) {
        if (errno == EEXIST) {
            printf("file exists already and oxcl not allowing it to open");
        } else {
            perror("Error opening file");
            return 1;
        }
    } else {
        printf("File opened successfully in read-write mode.\n");
        close(fd);
    }

    return 0;
}

