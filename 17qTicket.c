#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1){
        write(2, "Open error\n", 11);
        return -1;
    }
    write(fd, "100", 3);
    close(fd);
    return 0;
}