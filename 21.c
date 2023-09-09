#include <stdio.h>
#include <unistd.h>

int main(){
if(fork()){
	int id =getpid();
	printf(" Parents process id is :    %d \n",id);
}                  
else{
	int id = getpid();
	printf("Childs process id is : %d \n",id);
}
return 0;
}

	
