#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	pid_t pid[3]; 
	int status;

	printf("Parent process: PID: %d\n",getpid());

	for(int i=0;i<3;i++){ 
		pid[i] = fork();

		if(pid[i]<0){
			perror("Unable to fork the process\n");
			return -1;
		}
		else if(pid[i]==0){
			printf("Child process %d : PID: %d is created\n",i+1,getpid());
			sleep(i+1);
			printf("Child process %d : PID: %d is exiting\n",i+1,getpid());
			exit(i+10);
		}
	}

	sleep(1);
	pid_t terminated_pid  = waitpid(pid[1],&status,0); 
	if(terminated_pid >0){
		if(WIFEXITED(status)){ 
			printf("Parent detected Child 2 (PID: %d) finished with exit code: %d\n",terminated_pid,WEXITSTATUS(status));
		}
	}
	else{
		perror("waitid failed\n");
	}

	printf("Parent process is now exiting\n");
	return 0;
}
