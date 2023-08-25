#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
        if(argc!=2)
        {
                printf("uh only one file no more no less\n");
                return -1;
        }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024]; 
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            char currentChar = buffer[i];
            ssize_t bytesWritten = write(1, &currentChar, 1);

            if (bytesWritten == -1) {
                perror("Error writing to STDOUT");
                close(fd);
                return 1;
            }

            if (currentChar == '\n') {
                break;
            }
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

