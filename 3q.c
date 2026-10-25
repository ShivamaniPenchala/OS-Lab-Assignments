#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){	
	int fd = creat("3q.txt", 0777);
	printf("the file Descriptor no. is : %d\n", fd);
	close(fd);
	return 0;
}
