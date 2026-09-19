#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("records.txt", O_RDWR);
    if(fd == -1){
        write(2, "open error\n", 11);
        return -1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 10;
    lock.l_len = 10;

    if(fcntl(fd, F_SETLKW, &lock) == -1){
        write(2, "lock error\n", 11);
        close(fd);
        return -1;
    }
    lseek(fd, 0, SEEK_SET);
    write(1, "Record 2 locked\n", 16);

    sleep(20);

    lseek(fd, 10, SEEK_SET);
    write(fd, "abcdefgh", 8);

    write(1, "Record 2 modified\n", 18);

    lock.l_type = F_UNLCK;

    if(fcntl(fd, F_SETLK, &lock) == -1)
    {
        write(2, "Unlock error\n", 13);
        close(fd);
        return -1;
    }
    
    write(1, "Record 2 unlocked\n", 18);

    close(fd);

    return 0;
    
}