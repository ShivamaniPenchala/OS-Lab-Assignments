#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd = creat("1qabc.txt", 0777);
	if (fd == -1)
	{
		write(2, "create error\n", 13);
		return -1;
	}

	if (symlink("1qabc.txt", "1qabc_soft_link.txt") == -1)
	{
		write(2, "symlink error\n", 14);
		close(fd);
		return -1;
	}
	write(1, "soft link created successfully\n", 32);

	if (link("1qabc.txt", "1qabc_Hard_link.txt") == -1)
	{
		write(2, "Hard link error\n", 16);
		close(fd);
		return -1;
	}
	write(1, "Hard link created successfully\n", 32);

	if (mknod("1qabcpipe.txt", S_IFIFO | 0777, 0) == -1)
	{
		write(2, "mknod error\n", 12);
		close(fd);
		return -1;
	}
	write(1, "Pipe  created successfully\n", 27);

	return 0;
}
