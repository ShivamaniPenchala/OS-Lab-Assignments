#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd = creat("1qabc.txt", 0777);

	symlink("1qabc.txt", "1qabc_soft_link.txt");
	write(1, "soft link created successfully\n", 32);

	link("1qabc.txt", "1qabc_Hard_link.txt");
	write(1, "Hard link created successfully\n", 32);

	mknod("1qabcpipe.txt", S_IFIFO | 0777, 0);
	write(1, "Pipe  created successfully\n", 27);

	return 0;
}
