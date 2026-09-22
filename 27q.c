#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<errno.h>

void print_priority_range(int policy, const char *  policy_name){
	      int max_pri = sched_get_priority_max(policy);
	      int min_pri = sched_get_priority_min(policy);

	      if(max_pri == -1 || min_pri == -1){
		      perror("sched_get_priority error");
		      return;
	      }
	      printf("Policy: %s : Min Priority = %d, Max Priority = %d\n",policy_name,min_pri,max_pri);
}

int main(){
	print_priority_range(SCHED_FIFO,"SCHED_FIFO (Real Time)");
	print_priority_range(SCHED_RR,"SCHED_RR (Real Time)");
	return 0;
}
