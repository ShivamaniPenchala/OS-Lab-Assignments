#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0){
        printf("Child Process ID: %d\n", getpid());
    }
    else if(pid > 0){
        printf("Parent Process ID: %d\n", getpid());
    }
    return 0;
}