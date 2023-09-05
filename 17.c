#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Ticket {
    int ticketNumber;
};

int main() {
    struct Ticket ticket;
    ticket.ticketNumber = 100; 

    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, &ticket, sizeof(struct Ticket)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
    printf("Ticket number stored: %d\n", ticket.ticketNumber);

    return 0;
}

