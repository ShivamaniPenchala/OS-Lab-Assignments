#include <unistd.h>
#include <fcntl.h>

int main()
{
    int count = 0;

    while(1){
        for(int i = 1; i <= 5; i++){
            char filename[50] = "file_";
            int n = count * 10 + i;

            if(n < 10){
                filename[5] = '0' + n;
                filename[6] = '\0';
            }
            else{
                filename[5] = '0' + (n / 10);
                filename[6] = '0' + (n % 10);
                filename[7] = '\0';
            }

            int fd = creat(filename, 0666);

            if(fd == -1){
                write(2, "creat error\n", 12);
                return -1;
            }

            write(1, filename, 7);
            write(1, " created\n", 9);

            close(fd);
        }

        count++;
    }

    return 0;
}