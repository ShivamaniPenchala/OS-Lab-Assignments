#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	off_t position;
	char data1[] = "0123456789";
	char data2[] = "ABCDEFGHIJ";
	fd = open("test.txt",O_RDWR | O_CREAT | O_TRUNC , 0644);
	if(fd==-1){
		perror("Unable to open file");
		return -1;
	}
	write(fd , data1 , 10);
	position = lseek(fd,10,SEEK_CUR);
	if(position == (off_t)-1){
		write(2, "lseek failed", 13);
		close(fd);
		return -1;
	}
	printf("File pointer position after lseek: %ld\n",(long)position);
	write(fd,data2,10);
	close(fd);
	return 0;
}
