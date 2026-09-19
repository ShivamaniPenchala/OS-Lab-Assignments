#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){
	if(symlink("shivamani.txt", "prateeksh.txt") == -1){
		perror("not working daa");
		return 1;
	}
	printf("its working \n");
	return 0;
}
