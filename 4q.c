#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("1qabc.txt", O_RDWR | O_CREAT | O_EXCL, 0777);
	printf("File Successfully Created with FD : %d\n", fd);
	close(fd);
	return 0;
}
