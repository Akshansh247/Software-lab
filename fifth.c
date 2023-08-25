#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
        if(argc!=6)
        {
                printf("only five files\n");
                return -1;
        }

 mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    while (1) {
        for (int i =1; i < 6; i++) {
            int fd = creat(argv[i], mode);
            if (fd == -1) {
                perror("Error creating file");
                return 1;
            }
            printf("File created: %s\n", argv[i]);
            close(fd);
        }
    }

    return 0;
}

