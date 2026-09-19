#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
	int fd = creat("3q.txt", 0777);
	if(fd == -1){
		write(2, "creat error\n", 12);
		return -1;
	}

	char buff[1];
        buff[0]	= fd + '0';
	write(1, "the file Descriptor no. is : ", 29);
	write(1, buff, 1);
	write(1, "\n", 1);
	close(fd);
	return 0;
}
