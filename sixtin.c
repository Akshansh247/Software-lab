#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("locked_file.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    
    struct flock writeLock;
    writeLock.l_type = F_WRLCK;
    writeLock.l_start = 0;
    writeLock.l_whence = SEEK_SET;
    writeLock.l_len = 0; 

    if (fcntl(fd, F_SETLK, &writeLock) == -1) {
        perror("Error acquiring write lock");
        close(fd);
        return 1;
    }

    printf("Write lock acquired. type enything to release the lock...\n");
    getchar();

   
    writeLock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &writeLock) == -1) {
        perror("Error releasing write lock");
        close(fd);
        return 1;
    }

    
    struct flock readLock;
    readLock.l_type = F_RDLCK;
    readLock.l_start = 0;
    readLock.l_whence = SEEK_SET;
    readLock.l_len = 0; 

    if (fcntl(fd, F_SETLK, &readLock) == -1) {
        perror("Error acquiring read lock");
        close(fd);
        return 1;
    }

    printf("Read lock acquired. Press anything to unlock .\n");
    getchar();

   
    readLock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &readLock) == -1) {
        perror("Error releasing read lock");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

