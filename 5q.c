#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int count = 0;
    char filename[50];
    while(1){
        for(int i = 1; i <= 5; i++){
            sprintf(filename, "file_%d", i);
            int fd = creat(filename, 0666);
            printf("%s created", filename);
            close(fd);
        }
        count++;
    }
    return 0;
}