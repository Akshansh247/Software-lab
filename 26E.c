#include <unistd.h>
int main(){
	char *arg[] = {"ls","-Rl",NULL};
	execvp("ls",arg);
	return 0;
}
