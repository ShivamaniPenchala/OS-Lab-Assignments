#include <signal.h>
int main()
{
    kill(getpid(), SIGSTOP);
    return 0;
}