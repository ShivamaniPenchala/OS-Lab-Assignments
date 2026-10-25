#include <stdio.h>
#include <sched.h>

int main()
{
    int minp = sched_get_priority_min(SCHED_FIFO);;
    int maxp = sched_get_priority_max(SCHED_FIFO);;

    if (minp == -1 || maxp == -1)
    {
        perror("error\n");
        return -1;
    }

    printf("Minimum real-time priority = %d\n", minp);
    printf("Maximum real-time priority = %d\n", maxp);

    return 0;
}