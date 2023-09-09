 #include <unistd.h>
 #include <stdlib.h>
 
int main(){
	char* arg[]={"ls","-Rl",NULL};
	execv("/bin/ls" ,arg);
	return 0;
}
