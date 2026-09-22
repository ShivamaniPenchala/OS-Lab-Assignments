#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("records.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1)
    {
        write(2, "Open error\n", 11);
        return -1;
    }

    write(fd, "1000000000", 10);
    write(fd, "2000000000", 10);
    write(fd, "3000000000", 10);

    close(fd);

    write(1, "Three records created\n", 22);

    return 0;
}