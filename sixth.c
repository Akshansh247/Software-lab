#include <unistd.h>

int main() {
    char buffer[1024]; 

    while (1) {
        ssize_t Read = read(0, buffer, sizeof(buffer));

        if (Read == -1) {
            return 1;
        }

        if (Read == 0) {
            break;
        }

        ssize_t Write = write(1, buffer, Read);

        if (Write == -1) {
       
            return 1;
        }
    }

    return 0;
}

