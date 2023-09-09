#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
	int pid =fork();
	int id1,id2,id3;
	if(pid ==0){
		sleep(12);
         id1 =getpid();
	 printf("I am the first child did my father wait? ");
	
      return 0;	}
	pid = fork();
	if (pid==0){
			id2 =getpid();
      
	sleep(10);
			return 0;
	}
         
	pid = fork();
	if(pid==0){
		id3 = getpid();
	sleep(20);
	printf("nobody waits for me huh ");
		
	
      return 0;	}	int stat=0;

	waitpid(id2,&stat,0);
           if(WIFEXITED(stat)){
		   printf("seond died \n");}


	return 0;
}

