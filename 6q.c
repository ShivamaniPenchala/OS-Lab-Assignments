#include <unistd.h>

int main()
{
	char buff[20];
	int n = read(0, buff, 20);
	write(1, buff, n);
	return 0;
}
