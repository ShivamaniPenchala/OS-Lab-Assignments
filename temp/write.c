#include <unistd.h>

int main() {
    char *msg = "Hello, World!\n";
    write(3, msg, 14);  // fd 1 = stdout, 14 = length of string
    return 0;
}
