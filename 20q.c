#include <unistd.h>
#include <sys/types.h>

void print_number(pid_t n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n = n / 10;
    }

    while (i > 0)
    {
        i--;
        write(1, &buffer[i], 1);
    }
}

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        write(2, "fork failed\n", 12);
        return -1;
    }

    if (pid == 0)
    {
        write(1, "Child Process ID: ", 18);
        print_number(getpid());
        write(1, "\n", 1);
    }
    else
    {
        write(1, "Parent Process ID: ", 19);
        print_number(getpid());
        write(1, "\n", 1);
    }

    return 0;
}