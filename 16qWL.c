#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("lockfile.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);

    if (fd == -1)
    {
        write(2, "fd error\n", 9);
        return -1;
    }

    write(fd, "0123456789\n", 11);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        write(2, "lock error\n", 11);
        close(fd);
        return -1;
    }

    write(1, "write lock is set for 15 sec\n", 29);

    sleep(15);

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        write(2, "unlock error\n", 13);
        close(fd);
        return -1;
    }

    write(1, "write lock released\n", 20);

    close(fd);

    return 0;
}