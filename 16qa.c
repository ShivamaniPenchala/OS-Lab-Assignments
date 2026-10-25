#include <unistd.h>
#include <fcntl.h>

int main()
{

    struct flock lock;
    int fd = open("lockfile.txt", O_WRONLY);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    write(1, "Trying to get lock...\n", 22);

    fcntl(fd, F_SETLKW, &lock);

    write(1, "Write Lock acquired\n", 20);
    write(fd, "abcdefghij\n", 10);
    write(1, "Write completed\n", 16);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    write(1, "write lock released\n", 20);

    close(fd);

    return 0;
}