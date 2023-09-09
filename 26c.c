#include <unistd.h>
int main(){
	char *env[]={"DIR = /home/aksh2002/SS_lab",NULL};
		execle("/usr/bin/ls","ls","-Rl","/home/aksh2002/SS_lab",(char*)NULL,env);
		return 0;
	}
