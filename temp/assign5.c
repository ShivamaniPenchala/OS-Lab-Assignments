#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int j = 1;
	while(1){
		if(j == 1){
			char filename[50];
			for(int i = 0; i < 5; i++){
				sprintf(filename, "file_%d", i+1);
				int fd = open(filename, O_CREAT , 0777);
				if(fd == -1){
					perror("error");
					return -1;
				}
				printf("%s\n", filename);
				sleep(4);
			}
		j = 0;
		}

	}
	return 0;
}



