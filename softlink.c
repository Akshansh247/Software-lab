#include <unistd.h>
#include <stdio.h>

int main(int argc ,char* argv[]){
	if(argc!=3)
	{
		printf("no this is not the way");
		return -1;
	}
	int link = symlink(argv[1],argv[2]);
	if(link!=0){
		printf("sorry couldn't link");
		return -1;
	}

	return 0;
}

