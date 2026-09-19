#include <unistd.h>
#include <stdio.h>

int main(){
	if(link("shivamani.txt", "nihal.txt") == -1){
		perror("not working");
		return 1;
	}
	return 0;
}
