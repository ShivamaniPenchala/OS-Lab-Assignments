#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	char *args[] = {"ls", "-R", "-I", "*.txt", NULL};
	char *env = {NULL};
	if(argc!=2){
		write(1,"Usage: ./execdemo <1-5>\n",25);
		write(1,"1. exec\n", 10);
		write(1,"2. execlp\n", 11);
		write(1,"3. execle\n", 11);
		write(1,"4. execv\n", 10);
		write(1,"5. execvp\n", 11);
		return -1;
	}
	switch(argv[1][0]){
		case '1':
			execl("/bin/ls","ls","-R","-I","*.txt",(char *)NULL);
			write(1,"execl failed\n",14);
			break;

		case '2':
			execlp("/bin/ls","ls","-R","-I","*.txt",(char *)NULL);
			write(1,"execlp failed\n",15);
			break;

		case '3':
			execle("/bin/ls","ls","-R","-I","*.txt",(char *)NULL,env);
			write(1,"execle failed\n", 15);
			break;

		case '4':
			execv("/bin/ls",args);
			write(1,"execv failed\n",14);
			break;
		case '5':
			execvp("ls",args);
			write(1,"execvp failed\n", 15);
			break;
		default:
			write(1, "invalid choice\n", 15);
	}	
	return 0;
}


