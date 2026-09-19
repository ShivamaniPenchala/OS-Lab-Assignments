#include <stdio.h>
#include <unistd.h>
#include <sys/sysmacros.h>
int main(){
	if(mkfifo("pipe1", 0666) == -1){
		perror("not working");
		return 1;
	}
	return 0;
}
