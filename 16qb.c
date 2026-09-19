#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("lockfile.txt", O_RDONLY);

    if (fd == -1)
    {
        write(2, "fd error\n", 9);
        return -1;
    }

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 10;

    write(1, "Trying to get lock...\n", 22);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        write(1, "lock error\n", 11);
        close(fd);
        return -1;
    }

    write(1, "READ Lock acquired\n", 19);

    char *buff[100];

    int n = read(fd, buff, 100);

    write(1, buff, n);

    write(1, "\n", 1);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    write(1, "read lock released\n", 19);

    close(fd);

    return 0;
}