#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int pid =fork();
  if(pid ==0){
  exit(0);
  }  
	sleep (100);
	return 0;
}
