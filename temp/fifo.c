
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
	if(mknod("mypipe", S_IFIFO | 0666, 0) == -1){
		perror("something is Worng");
		return -1;
	}
	printf("Pipe is created Successfully \n");
	return 0;
} 
