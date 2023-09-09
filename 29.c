#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sched.h>
int main(){
	int policy = sched_getscheduler(0);
	struct sched_param param;
      if(policy ==-1){
	      perror("sched_getparam");
	      exit(1);
      }
     int pr =  sched_getparam(0,&param);
     if(pr ==-1){
	     perror("sched_getparam");
	     exit(1);
     }
     
     printf("Old scheduling policy :  ");
     switch(policy){
	     case SCHED_FIFO:
		     printf("SCHED_FIFO\n");
		     break;
             case SCHED_RR:
		     printf("SCHED_RR\n");
		     break;
	     case SCHED_OTHER:
		     printf("SCHED_OTHER\n");
		     break;
	     default:
		     printf("uh I don't know\n");
	
     }
  int priority = param.sched_priority;
printf("Current priority : %d \n" ,  priority);

struct sched_param newpara;
newpara.sched_priority =50;
int set = sched_setscheduler(0,SCHED_RR,&newpara);
if(set == -1){
	perror("sched_setscheduleer");
	exit(1);
}
policy = sched_getparam(0,&param);
printf("%d\n",param.sched_priority);

return 0;}
