#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{

	int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	if (fd == -1)
	{
		write(2, "testfile creation error", 23);
		return -1;
	}
	write(fd, "original testfile.txt\n", 22);

	int dupfd1 = dup(fd);
	if (dupfd1 == -1)
	{
		write(2, "dup fd1 creation error", 22);
		close(fd);
		return -1;
	}
	write(fd, "dup testfile.txt\n", 17);


	int dupfd2 = dup2(fd, 10);
	if (dupfd2 == -1)
	{
		write(2, "dupfd2 creation error", 22);
		close(fd);
		return -1;
	}
	write(fd, "dup2 testfile.txt\n", 18);

	int dupfd3 = fcntl(fd, F_DUPFD, 10);
	if (dupfd3 == -1)
	{
		write(2, "dupfd2 creation error", 22);
		close(fd);
		return -1;
	}
	write(fd, "fcntl testfile.txt\n", 19);

	close(fd);
	close(dupfd1);
	close(dupfd2);
	close(dupfd3);

	return 0;
}
