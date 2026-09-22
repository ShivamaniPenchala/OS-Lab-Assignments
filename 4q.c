#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("1qabc.txt", O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd == -1)
	{
		write(2, "file Already Exists\n", 20);
		return -1;
	}
	char buff[50] = "File Successfully Created with FD : ";
	write(1, buff, sizeof(buff));
	buff[0] = fd + '0';
	write(1, buff, 1);
	write(1, "\n", 1);
	close(fd);
	return 0;
}
