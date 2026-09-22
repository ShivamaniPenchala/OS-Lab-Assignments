#include <unistd.h>

extern char **environ;

int main()
{
	int i = 0;
	while (environ[i] != NULL)
	{
		char *temp = environ[i];
		int j = 0;
		while (temp[j] != '\0')
		{
			j++;
		}
		write(1, temp, j);
		write(1, "\n", 1);
		i++;
	}
	return 0;
}
