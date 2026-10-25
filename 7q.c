#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("txtfile.txt", O_RDONLY);
	int fd2 = open("cpfile.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	char buff[100];
	int n;
	while (n = (read(fd1, buff, 100)) > 0)
	{
		write(fd2, buff, n);
	}
	close(fd1);
	close(fd2);
	write(1, "copied successfully", 19);
	write(1, "\n", 1);
	return 0;
}
