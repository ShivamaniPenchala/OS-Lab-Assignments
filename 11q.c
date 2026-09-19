#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){

	int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	if(fd == -1){
		write(2, "testfile creation error", 23);
		return -1;
	}
	const char *buff = "i am from original testfile.txt, written using fd\n";
	write(fd, buff, strlen(buff));

	int dupfd1 = dup(fd);
	if(dupfd1 == -1){
		write(2, "dup fd1 creation error", 22);
		close(fd);
		return -1;
	}
	const char *buff1 = "i am from dup file descriptor dupfd1, using dup()\n";
	write(dupfd1, buff1, strlen(buff1));

	int dupfd2 = dup2(fd, 10);
	if(dupfd2 == -1){
		write(2, "dupfd2 creation error", 22);
		close(fd);
		return -1;
	}
	const char *buff2 = "i am from dup file descriptor dupfd2, using dup2()\n";
	write(dupfd2, buff2, strlen(buff2));
	
	int dupfd3 = fcntl(fd,F_DUPFD ,10);
	if(dupfd3 == -1){
		write(2, "dupfd2 creation error", 22);
		close(fd);
		return -1;
	}
	const char *buff3 = "i am from dup file descriptor dupfd3, using fcntl()\n";
	write(dupfd3, buff3, strlen(buff3));

	close(fd);
	close(dupfd1);
	close(dupfd2);
	close(dupfd3);

	return 0;
}



