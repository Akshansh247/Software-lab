#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        if(argc!=2)
        {
                printf("this isn't the way");
                return -1;
        }
    
    int f = mkfifo(argv[1], 0666);

    if (f!=0){
	    printf("nah fifo isn't going to be created");
    return -1;
    }
    return 0;
}

