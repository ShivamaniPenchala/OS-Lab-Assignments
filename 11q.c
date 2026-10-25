#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	write(fd, "original testfile.txt\n", 22);

	int dupfd1 = dup(fd);
	write(fd, "dup testfile.txt\n", 17);

	int dupfd2 = dup2(fd, 10);
	write(fd, "dup2 testfile.txt\n", 18);

	int dupfd3 = fcntl(fd, F_DUPFD, 10);
	write(fd, "fcntl testfile.txt\n", 19);

	close(fd);
	close(dupfd1);
	close(dupfd2);
	close(dupfd3);

	return 0;
}
