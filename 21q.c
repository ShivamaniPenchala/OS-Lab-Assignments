#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    pid_t pid = fork();

    if(pid == 0){
        write(fd, "Child process writing\n", 22);
    }
    else if(pid > 0){
        write(fd, "Parent process writing\n", 23);
    }
    close(fd);
    return 0;
}