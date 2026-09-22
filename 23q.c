#include<unistd.h>
int main(){
	pid_t pid = fork();
	if (pid<0){
		write(1,"Fork failed\n",12);
		return -1;
	}
	if (pid>0){
		write(1,"Parent process is terminating...\n", 34);
		return 0;
	}
	else{
		sleep(3);
		write(1,"Parent has terminated, but child is still active.\n",50);
		sleep(5);
		write(1,"Child process is now terminating.\n",35);
	}
	return 0;
}

