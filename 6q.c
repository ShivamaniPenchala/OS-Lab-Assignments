#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main(){
	char buff[20];
	read(0, buff, 20);
	char buff2[100];
	sprintf(buff2, "My Name is %s", buff);
	write(1, buff2, strlen(buff2));
	return 0;
}
