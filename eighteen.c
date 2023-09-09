#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Record {
    int id;
    char name[50];
    char email[100];
};


void lock_file(int fd) {
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0; 

    fcntl(fd, F_SETLKW, &fl);
}


void unlock_file(int fd) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0; 

    fcntl(fd, F_SETLKW, &fl);
}

int main() {
    int fd = open("records.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

  
    lock_file(fd);
getchar();
    struct Record records[3] = {
        {1, "AKshansh jain", "aksh@gmaile.com"},
        {2, "Somebody SOmbedy", "some@gmail.com"},
        {3, "okaythis this", "thisis@outlook.com"}
    };

   
    for (int i = 0; i < 3; i++) {
	    struct Record r;
        write (fd, &records[i], sizeof(r));
    }

    
    unlock_file(fd);

    close(fd);
printf("done the updatation");
    return 0;
}

