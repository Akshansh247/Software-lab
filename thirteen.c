#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

    int result = select(1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("Error in select");
        return 1;
    } else if (result == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            printf("Data is available on STDIN within 10 seconds!\n");
      
        }
    }

    return 0;
}

