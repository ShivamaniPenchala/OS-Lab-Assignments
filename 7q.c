#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd1 = open("txtfile.txt", O_RDONLY);
	if(fd1 == -1){
		write(2, "txtfile.txt opening error", 25);
		return -1;
	}
	int fd2 = open("cpfile.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if(fd2 == -1){
		write(2, "cpflie.txt opening error", 24);
		close(fd1);
		return -1;
	}
	char buff[100];
	int n;
	while(n = (read(fd1, buff, 100)) > 0){
		write(fd2, buff, n);
	}
	close(fd1);
	close(fd2);
	write(1, "copied successfully", 19);
	write(1, "\n", 1);
	return 0;
}

