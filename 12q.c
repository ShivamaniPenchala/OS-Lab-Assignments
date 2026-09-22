#include <fcntl.h>
#include <unistd.h>

int main()
{

	int fd1 = open("testfile.txt", O_RDONLY);
	if (fd1 == -1)
	{
		write(2, "fd1 error", 9);
		return -1;
	}

	int fd2 = open("txtfile.txt", O_WRONLY);
	if (fd2 == -1)
	{
		write(2, "fd2 error", 9);
		close(fd1);
		return -1;
	}

	int fd3 = open("test.txt", O_RDWR);
	if (fd3 == -1)
	{
		write(2, "fd3 error", 9);
		close(fd1);
		close(fd2);
		return -1;
	}

	int f1flag = fcntl(fd1, F_GETFL);
	if (f1flag == -1)
	{
		write(2, "f1flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}
	
	int f2flag = fcntl(fd2, F_GETFL);
	if (f2flag == -1)
	{
		write(2, "f2flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}
	
	int f3flag = fcntl(fd3, F_GETFL);
	if (f3flag == -1)
	{
		write(2, "f3flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}

	int mode[3];
	mode[0] = f1flag & O_ACCMODE;
	mode[1] = f2flag & O_ACCMODE;
	mode[2] = f3flag & O_ACCMODE;
	
	for (int i = 1; i <= 3; i++)
	{	
		char fdtext[3] = "FD"; 
		fdtext[2] = '0' + i;
		write(1, fdtext, 3);

		if (mode[i - 1] == O_RDONLY)
		{	
			write(1, " - read only mode\n", 18);
		}
		else if (mode[i - 1] == O_WRONLY)
		{
			write(1, " - Write only mode\n", 19);
		}
		else if (mode[i - 1] == O_RDWR)
		{
			write(1, " - Read and Write mode\n", 23);
		}
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}
