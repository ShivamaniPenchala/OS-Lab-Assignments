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

    write(fd, "1111111111\n", 11);

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 10;

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        write(2, "lock error\n", 11);
        close(fd);
        return -1;
    }

    write(1, "read lock is set for 15 sec\n", 28);

    sleep(15);

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        write(2, "unlock error\n", 13);
        close(fd);
        return -1;
    }

    write(1, "read lock released\n", 19);

    close(fd);

    return 0;
}