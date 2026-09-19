#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;

    pid = getpid();

    if(kill(pid, SIGSTOP) == -1)
    {
        write(2, "Kill failed\n", 12);
        return -1;
    }

    write(1, "Process stopped\n", 16);


    return 0;
}