#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("ticket.txt", O_RDWR);
    if(fd == -1){
        write(2, "Open error\n", 11);
        return -1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd, F_SETLKW, &lock) == -1){
        write(2, "lock error\n", 11);
        close(fd);
        return -1;
    }
    write(1, "Pls wait for 10 secs\n", 21);
    sleep(10);
    char buff[25];
    lseek(fd, 0, SEEK_SET);
    int n = read(fd, buff, sizeof(buff));
    if(n <= 0){
        write(2, "read error\n", 11);
        close(fd);
        return -1;
    }

    int ticket = 0;
    for(int i = 0; i < n; i++){
        if(buff[i] >= '0' && buff[i] <= '9'){
            ticket = ticket * 10 + (buff[i] - '0');
        }
    }
    
    ticket++;

    char output[20];
    int i = 0;

    if (ticket == 0)
    {
        output[i++] = '0';
    }
    else
    {
        char digits[20];
        int j = 0;
        int temp = ticket;

        while (temp > 0)
        {
            digits[j++] = (temp % 10) + '0';
            temp /= 10;
        }

        while (j > 0)
        {
            output[i++] = digits[--j];
        }
    }
    lseek(fd, 0, SEEK_SET);
    write(fd, output, i);
    write(1, "New ticket number: ", 19);
    write(1, output, i);
    write(1, "\n", 1);

    lock.l_type = F_UNLCK;
    if(fcntl(fd, F_UNLCK, &lock) == -1){
        write(2, "unlock error\n", 13);
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}