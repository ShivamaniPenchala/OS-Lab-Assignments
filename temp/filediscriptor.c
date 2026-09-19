
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1;
	int fd2;
	fd1 = creat("fileDiscriptor.txt", 0777);
	fd2 = creat("fileD", 0777);
	if(fd1 == -1){
		perror("something is wrong");
		return 1;
	}
	if(fd2 == -1){
		perror("fd 2 error");
		return 1;
	}
	printf("file Discriptor %d\n", fd1);
	printf("file Discriptor %d\n", fd2);
	return 0;
}
