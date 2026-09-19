#include <unistd.h>
#include <string.h>
int main(){
	char buffer[100];
	int n = read(0, buffer, 100);
	buffer[n] = '\0';
	char temp[100] = "My name is ";
	strcat(temp, buffer);
	write(1, temp, n);
	return 0;
}
