#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(){
	int fd = open("textfile.txt", O_CREAT | O_RDWR, 0777);
	if(fd == -1){
		perror("error");
		return -1;
	}
	printf("successfull\n");
	printf("file Descriptor : %d\n", fd);
	return 0;
}
	
