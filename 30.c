#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    
    int pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    
    if (pid > 0) {
        printf("ending for real ,hope  %d also ends ", pid);
        exit(0);
    }

   if(pid==0){ 
    if (setsid() < 0) {
        perror("setsid");
        exit(1);
    }

  
    chdir("/");

    umask(0);

   
    while(1) {
        system("home/aksh2002/SS_lab/030/script.sh");
        sleep(10);
    } }

    return 0;
}

