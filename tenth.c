#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
	if(argc!=2){
		printf("one file no more no less");
		return -1;}
    int fd = open(argv[1], O_RDWR );

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char* data1 = "first haha"; 
    const char* data2 = "ok second "; 

    ssize_t bytes_written = write(fd, data1, 10);

    if (bytes_written != 10) {
        perror("Error writing data1");
        close(fd);
        return 1;
    }

    off_t offset = lseek(fd, 10, SEEK_CUR);

    if (offset == -1) {
        perror("Error seeking");
        close(fd);
        return 1;
    }

    bytes_written = write(fd, data2, 10);

    if (bytes_written != 10) {
        perror("Error writing data2");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Data written and file pointer moved successfully.\n");

    return 0;
}

