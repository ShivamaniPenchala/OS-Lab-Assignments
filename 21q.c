#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1)
    {
        write(2, "Open error\n", 11);
        return -1;
    }

    pid = fork();

    if (pid < 0)
    {
        write(2, "Fork failed\n", 12);
        close(fd);
        return -1;
    }

    if (pid == 0)
    {
        write(fd, "Child process writing\n", 22);
    }
    else
    {
        write(fd, "Parent process writing\n", 23);
    }

    close(fd);

    return 0;
}