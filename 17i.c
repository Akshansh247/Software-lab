#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Ticket {
    int ticketNumber;
};

int main() {


    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sizeof(struct Ticket);
 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error locking file");
        return 1;
    }

    struct Ticket ticket;
    if (read(fd, &ticket, sizeof(struct Ticket)) == -1) {
        perror("Error reading ticket");
        return 1;
    }

    ticket.ticketNumber++;
    
    lseek(fd, 0, SEEK_SET);
    if (write(fd, &ticket, sizeof(struct Ticket)) == -1) {
        perror("Error writing to file");
        return 1;
    
    }
    
    getchar();

    printf("New Ticket number: %d\n", ticket.ticketNumber);
    lock.l_type = F_UNLCK;  
   fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}

