#include <unistd.h>
int main(){
	char *path ="/bin/ls";
	char *arg1 = "-Rl";
	
	execl(path ,path ,arg1,NULL);
return 0;
}
