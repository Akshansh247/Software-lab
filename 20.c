#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int priority;
    
   
    priority = getpriority(PRIO_PROCESS, getpid());
   

    printf("Current Priority: %d\n", priority);

    int value =0;
    printf("enter the new priority value you want to set\n");
    scanf("%d",&value);
   
    nice(value);

    int priority_after=0;
    priority_after = getpriority(PRIO_PROCESS, getpid());
    if (priority_after == -1) {
        perror("getpriority");
        return 1;
    }

    printf("New Priority: %d\n",priority_after);

    return 0;
}

