#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t child1, child2, child3;
    int status;
    child1 = fork();

    if (child1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 exiting...\n");
        exit(1);
    }

    child2 = fork();

    if (child2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(5);
        printf("Child 2 exiting...\n");
        exit(2);
    }

    child3 = fork();

    if (child3 == 0)
    {
        printf("Child 3: PID = %d\n", getpid());
        sleep(3);
        printf("Child 3 exiting...\n");
        exit(3);
    }

    printf("Parent: PID = %d\n", getpid());

    printf("Parent is waiting for Child 2...\n");

    waitpid(child2, &status, 0);

    printf("Child 2 has terminated.\n");

    printf("Parent exiting...\n");

    return 0;
}