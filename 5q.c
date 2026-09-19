#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(){
	int j = 1;
	while(1){
		for(int i = 1; i <= 5; i++){
			char filename[50];
			sprintf(filename, "file_%d", j++);
			int fd = creat(filename, 0777);
			if(fd == -1){
				write(2, "creat error", 11);
				return -1;
			}
			char buff[100];
			sprintf(buff, "%s created Successfully with fd : %d", filename, fd);
			write(1, buff, strlen(buff));
			write(1, "\n", 1);
			sleep(3);
		}
	}
	return 0;
}
		
				
				
