#include <unistd.h>
int main()
{   
    execl("./execfile", "execfile", NULL);
    write(2, "exec error\n", 11);
    return -1;
}