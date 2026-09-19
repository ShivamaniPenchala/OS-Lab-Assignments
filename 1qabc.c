#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(){
	int fd = creat("1qabc.txt", 0777);
	if(fd == -1){
		perror("create error");
		return -1;

	}
	else{
		char buff[50] = "file Created Successfully\n";
		write(1, buff, sizeof(buff));
	}
	if(symlink("1qabc.txt", "1qabc_soft_link.txt") == -1){
		perror("symlink error");
		return -1;
	}
	else{
		char buff[50] = "soft link created successfully\n";
		write(1, buff, sizeof(buff));
	}
	if(link("1qabc.txt", "1qabc_Hard_link.txt") == -1){
		perror("Hard Link Error");
		return -1;
	}
	else{
		char buff[50] = "Hard link created successfully\n";
		write(1, buff, sizeof(buff));
	}

	if(mknod("1qabcpipe.txt", S_IFIFO | 0777, 0) == -1){
		perror("mknod error");
		return -1;
	}
	else{
		char buff[50] = "Pipe  created successfully\n";
		write(1, buff, sizeof(buff));
	}
	return 0;
}


	
