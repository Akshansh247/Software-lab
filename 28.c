#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main(){
	int min , max;
	min =sched_get_priority_min(SCHED_FIFO);
	printf("%d\n",min);
	max = sched_get_priority_max(SCHED_FIFO);
	printf("%d\n",max);
	return 0;
}
