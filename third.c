#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
        if(argc!=2)
        {
                printf("uh atleast and only one file\n");
                return -1;
        }

    
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = creat(argv[1],mode);

    if (fd==-1) {
        perror("Error creating file");
        return -1;
    }

    printf("Great you created the file and the  file descriptor is  %d \n", fd);

    close(fd); 
    
    return 0;
}

