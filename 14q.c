#include <unistd.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	struct stat st;
	if (argc != 2)
	{
		write(2, "no input found\n", 15);
		return -1;
	}

	if (stat(argv[1], &st) == -1)
	{
		write(2, "stat() error\n", 13);
		return -1;
	}

	if (S_ISREG(st.st_mode))
	{
		write(1, "regular file\n", 12);
	}
	else if (S_ISDIR(st.st_mode))
	{
		write(1, "Directory\n", 10);
	}

	else if (S_ISLNK(st.st_mode))
	{
		write(1, "Link\n", 5);
	}

	else if (S_ISFIFO(st.st_mode))
	{
		write(1, "Named Pipe\n", 11);
	}

	else if (S_ISCHR(st.st_mode))
	{
		write(1, "Character Device\n", 17);
	}

	else if (S_ISBLK(st.st_mode))
	{
		write(1, "Block\n", 6);
	}

	else if (S_ISSOCK(st.st_mode))
	{
		write(1, "Socket\n", 7);
	}
	else
	{
		write(1, "unknown file\n", 12);
	}

	return 0;
}
