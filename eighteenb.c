#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Record {
    int id;
    char name[50];
    char email[100];
};


void write_record(int fd, off_t offset) {
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = offset;
    fl.l_whence = SEEK_SET;
    fl.l_len = sizeof(struct Record);

    fcntl(fd, F_SETLKW, &fl);
}
void read_record(int fd, off_t offset) {
    struct flock fl;
    fl.l_type = F_RDLCK;
    fl.l_start = offset;
    fl.l_whence = SEEK_SET;
    fl.l_len = sizeof(struct Record);

    fcntl(fd, F_SETLKW, &fl);
}


void unlock_record(int fd, off_t offset) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_start = offset;
    fl.l_whence = SEEK_SET;
    fl.l_len = sizeof(struct Record);

    fcntl(fd, F_SETLKW, &fl);
}

int main() {
    int fd = open("records.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char input ='s';
    while(input !='X'){
printf("choose W for updating R for reading and X for exit: ");

scanf("%c",&input);
printf("\n");
 if(input =='W'){
    struct Record tempRecord;
    printf("Enter  ID: ");
    scanf("%d", &tempRecord.id);
    printf("Enter new name: ");
    scanf("%s", tempRecord.name);
    printf("Enter new email: ");
    scanf("%s", tempRecord.email);

    
    struct Record record;
    int found = 0;
    off_t offset = 0;
    while (read(fd, &record, sizeof(struct Record)) > 0) {
        if (record.id == tempRecord.id) {
            found = 1;

            offset = -sizeof(struct Record); 
            write_record(fd, offset);
	    getchar();
            getchar();
           
            lseek(fd, offset, SEEK_CUR);

          
            write(fd, &tempRecord, sizeof(struct Record));

            unlock_record(fd, offset);

           printf("record updated\n");
	   lseek(fd,0,SEEK_SET);
	   break;
        }
offset =  lseek(fd,0,SEEK_CUR);
    }

    if (!found) {
        printf("Record with ID %d not found.\n", tempRecord.id);
    }

    
 }
 else if(input =='R'){
	 printf("what do you want to see? \n");
	 int id=0;
	 scanf("%d",&id);
	  struct Record record;
    int found = 0;
    off_t offset = 0;
    while (read(fd, &record, sizeof(struct Record)) > 0) {
        if (record.id == id) {
            found = 1;

            offset = lseek(fd, 0, SEEK_CUR) - sizeof(struct Record);
            read_record(fd, offset);
	   
          
           
            printf("ID: %d\nName: %s\nEmail: %s\n", record.id, record.name, record.email);

            unlock_record(fd, offset);
break;
            
        }
       offset = lseek(fd, 0, SEEK_CUR);
      	
    }
    lseek(fd,0,SEEK_SET);
 }}
    close(fd);
    return 0;
}

