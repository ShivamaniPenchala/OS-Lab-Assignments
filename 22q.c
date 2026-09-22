#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {   
        int childpid = getpid();
        printf("Child exiting with pid : %d\n", childpid);
        _exit(0);
    }
    else
    {
        int parentpid = getpid();
        printf("parent sleeping with pid : %d\n", parentpid);
        sleep(120);
    }
    return 0;
}