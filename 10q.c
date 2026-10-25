#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char data1[] = "0123456789";
	char data2[] = "ABCDEFGHIJ";
	int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, data1, 10);
	off_t position = lseek(fd, 10, SEEK_CUR);
	printf("File pointer position after lseek: %d\n", position);
	write(fd, data2, 10);
	close(fd);
	return 0;
}
