#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int pid =fork();
	if(pid ==0){
		sleep(30);
printf("I am yet alive but father dead lmao");		
}
	return 0;
}
