#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
	int fd = open("txtfile.txt", O_RDONLY);
	if(fd == -1){
		write(2, "open error", 9);
		return -1;
	}
	char buff[100];
	int n;
	int i = 0;
	char ch;
	while( read(fd, &ch, 1) > 0){
		buff[i++] = ch;
		if(ch == '\n'){
			write(1, buff, i);
			i = 0;
			sleep(2);
		}	
	}
	if(i > 0) write(1, buff, i);
	close(fd);
	return 0;

}
