#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("lockfile.txt", O_WRONLY);

    if (fd == -1)
    {
        write(2, "fd error\n", 9);
        return -1;
    }

    lock.l_type = F_WRLCK;
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

    write(1, "Write Lock acquired\n", 20);

	lseek(fd, 5, SEEK_SET);

    write(fd, "abcdefghij\n", 10);

    write(1, "Write completed\n", 16);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    write(1, "write lock released\n", 20);

    close(fd);

    return 0;
}