#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[]) {

    int fd = open(argv[1], O_RDWR);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

  
    int fd2 = dup2(fd, 100);

    if (fd2 == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

  
    const char* data1 = "This is data written using original descriptor.\n";
    ssize_t write1 = write(fd, data1, strlen(data1));

    if (write1 == -1) {
        perror("Error writing using original descriptor");
        close(fd);
        close(fd2);
        return 1;
    }

    const char* data2 = "This is data written using duplicated descriptor.\n";
    ssize_t write2 = write(fd2, data2, strlen(data2));

    if (write2 == -1) {
        perror("Error writing using duplicated descriptor");
        close(fd);
        close(fd2);
        return 1;
    }

    close(fd);
    close(fd2);

    printf("Data written and file updated successfully.\n");

    return 0;
}

