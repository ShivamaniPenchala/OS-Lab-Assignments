#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int fd = open("shivamani.txt", O_RDWR | O_APPEND, 0644);
	if(fd == -1){
		perror("some issue");
		return 1;
	}
	printf("its working");
	const char *buffer = "i love pratheeksh";
	write(fd, buffer, strlen(buffer));
	return 0;
}
	
