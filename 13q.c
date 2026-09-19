#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    
    char buffer[100];

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    write(1, "Waiting for input for 10 seconds...\n", 37);

    int result = select(1, &readfds, NULL, NULL, &timeout);

    if (result == -1)
    {
        write(2, "select error\n", 13);
        return -1;
    }

    if (result == 0)
    {
        write(1, "No input received within 10 seconds\n", 36);
    }
    else
    {
        if (FD_ISSET(0, &readfds))
        {
            write(1, "Data is available on STDIN\n", 27);

            int n = read(0, buffer, sizeof(buffer));

            if (n > 0)
            {
                write(1, "Input: ", 7);
                write(1, buffer, n);
            }
        }
    }

    return 0;
}