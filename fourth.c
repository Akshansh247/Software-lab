#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "something.txt";
    
    int fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("Can not open ");
        return 1;
    }

    printf("File opened successfully in read-write mode.\n");

    close(fd); 
    
    return 0;
}

