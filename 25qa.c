#include <unistd.h>
int main()
{   
    write(1, "I'm an executable file\n", 23);
    return 0;
}