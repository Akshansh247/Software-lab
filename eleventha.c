#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[]) {
	if(argc!=2){
		printf("no it's not the way");
	}
 
    int fd1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

    int fd2 = dup(fd1);

    if (fd2 == -1) {
        perror("Error duplicating file descriptor");
        close(fd1);
        return 1;
    }

    const char* data = "using the original discripter\n";
    const char* data2 = "using the duplicate discripter\n";

    ssize_t bytes_written1 = write(fd1, data, strlen(data));

    if (bytes_written1 == -1) {
        perror("Error writing to file");
        close(fd1);
        close(fd2);
        return 1;
    }

    ssize_t bytes_written2 = write(fd2, data2, strlen(data));

    if (bytes_written2 == -1) {
        perror("Error writing to file");
        close(fd1);
        close(fd2);
        return 1;
    }

    close(fd1);
    close(fd2);

    printf("Data written and file updated successfully.\n");

    return 0;
}

