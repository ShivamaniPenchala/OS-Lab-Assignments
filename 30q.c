#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    
    if (fork() > 0) {
        exit(0); 
    }
    printf("PID of the child: %d\n",getpid());
    setsid();    
    
    int n = 0;
    while (1) {
        time_t now = time(NULL);
        struct tm *current = localtime(&now);
        int target_hour = 22;  
        int target_min = 20;

        if (current->tm_hour == target_hour && current->tm_min == target_min) {
            n++;
            printf("The daemon process is printing successfully : %d\n", n);
        }
        // sleep(5); 
	}	
 	return 0;
}
