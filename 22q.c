#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0){   
        printf("Child exiting with pid : %d\n", getpid());
        _exit(0);
    }
    else if(pid > 0){
        printf("parent sleeping with pid : %d\n", getpid());
        sleep(120);
    }
    return 0;
}