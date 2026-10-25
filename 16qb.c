#include <unistd.h>
#include <fcntl.h>

int main()
{
    struct flock lock;
    int fd = open("lockfile.txt", O_RDONLY);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    write(1, "Trying to get lock...\n", 22);
    fcntl(fd, F_SETLKW, &lock);
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