#include <stdio.h>
#include <unistd.h>
#include <sched.h>
checkPolicy(int policy){
	switch (policy)
	{
	case SCHED_OTHER:
		printf("SCHED_OTHER\n");
		break;
	case SCHED_FIFO:
		printf("SCHED_FIFO\n");
		break;
	case SCHED_RR:
		printf("SCHED_RR\n");
		break;
	default:
		printf("Unknown policy\n");
	}
}

int main()
{

	int policy;
	struct sched_param param;
	pid_t pid = getpid();
	int policy = sched_getscheduler(0);
	if (policy == -1)
	{
		perror("Error in returning scheduler");
		return -1;
	}
	printf("Process id : %d\n", pid);
	printf("Current scheduling policy: ");
	checkPolicy(policy);
	
	param.sched_priority = 1;
	if (sched_setscheduler(pid, SCHED_RR, &param) == -1)
	{
		perror("Error in setting scheduler");
		return -1;
	}
	printf("\n Scheduling policy modified successfully.\n");
	policy = sched_getscheduler(0);
	if (policy == -1)
	{
		perror("Error in returning scheduler");
		return -1;
	}
	printf("New Scheduling Policy: ");
	checkPolicy(policy);
	return 0;
}
