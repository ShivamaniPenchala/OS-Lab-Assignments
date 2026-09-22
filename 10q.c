#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_off_t(off_t n)
{
	char buff[30];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}

	while (n > 0)
	{
		buff[i++] = (n % 10) + '0';
		n = n / 10;
	}

	while (i > 0)
	{
		i--;
		write(1, &buff[i], 1);
	}
}

int main()
{
	int fd;
	off_t position;
	char data1[] = "0123456789";
	char data2[] = "ABCDEFGHIJ";
	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		return -1;
	}
	write(fd, data1, 10);
	position = lseek(fd, 10, SEEK_CUR);
	if (position == (off_t)-1)
	{
		write(2, "lseek failed", 13);
		close(fd);
		return -1;
	}
	write(1, "File pointer position after lseek: ", 35);
	print_off_t(position);
	write(1, "\n", 1);
	write(fd, data2, 10);
	close(fd);
	return 0;
}
