#include <fcntl.h>
#include <unistd.h>

int main(){

	int fd1 = open("testfile.txt", O_RDONLY);
	if(fd1 == -1){
		write(2, "fd1 error", 9);
		return -1;
	}

	int fd2 = open("txtfile.txt", O_WRONLY);
	if(fd2 == -1){
		write(2, "fd2 error", 9);
		close(fd1);
		return -1;
	}

	int fd3 = open("test.txt", O_RDWR);
	if(fd3 == -1){
		write(2, "fd3 error", 9);
		close(fd1);
		close(fd2);
		return -1;
	}

	int f1flag = fcntl(fd1, F_GETFL);
	if(f1flag == -1){
		write(2, "f1flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}
	int mode1 = f1flag & O_ACCMODE;

	int f2flag = fcntl(fd2, F_GETFL);
	if(f2flag == -1){
		write(2, "f2flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}
	int mode2 = f2flag & O_ACCMODE;


	int f3flag = fcntl(fd3, F_GETFL);
	if(f3flag == -1){
		write(2, "f3flag error", 12);
		close(fd1);
		close(fd2);
		close(fd3);
		return -1;
	}
	int mode3 = f3flag & O_ACCMODE;

	if(mode1 == O_RDONLY){
		write(1, "FD1 - read only mode\n", 21);
	}
	else if(mode1 == O_WRONLY){
		write(1, "FD1 - Write only mode\n", 22);
	}
	else if(mode1 == O_RDWR){
		write(1, "FD1 - Read and Write mode\n", 26);
	}

	if(mode2 == O_RDONLY){
		write(1, "FD2 - read only mode\n", 21);
	}
	else if(mode2 == O_WRONLY){
		write(1, "FD2 - Write only mode\n", 22);
	}
	else if(mode2 == O_RDWR){
		write(1, "FD2 - Read and Write mode\n", 26);
	}

	if(mode3 == O_RDONLY){
		write(1, "FD3 - read only mode\n", 21);
	}
	else if(mode3 == O_WRONLY){
		write(1, "FD3 - Write only mode\n", 22);
	}
	else if(mode3 == O_RDWR){
		write(1, "FD3 - Read and Write mode\n", 26);
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}

