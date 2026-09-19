#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
void print_number(long long int n){
	if(n == 0){
	       	write(1, "0", 1);
		return;
	}
	else{
		char num[20];
		int i = 0;
		while(n > 0){
			num[i++] = (n % 10) + '0';
			n /= 10;
		}
		while( i > 0){
			i--;
			write(1, &num[i], 1);
		}
	}
}

int main(int argc, char *argv[]){
	struct stat st;
	if(stat(argv[1], &st) == -1){
		write(2, "file problem", 12);
		return -1;
	}

write(1, "Inode : ", 8);
    print_number(st.st_ino);
    write(1, "\n", 1);

    write(1, "Hard links : ", 14);
    print_number(st.st_nlink);
    write(1, "\n", 1);

    write(1, "UID : ", 6);
    print_number(st.st_uid);
    write(1, "\n", 1);

    write(1, "GID : ", 6);
    print_number(st.st_gid);
    write(1, "\n", 1);

    write(1, "Size : ", 7);
    print_number(st.st_size);
    write(1, " bytes\n", 7);

    write(1, "Block size : ", 13);
    print_number(st.st_blksize);
    write(1, " bytes\n", 7);

    write(1, "Blocks : ", 9);
    print_number(st.st_blocks);
    write(1, "\n", 1);

    write(1, "Last access : ", 14);
    print_number(st.st_atime);
    write(1, "\n", 1);

    write(1, "Last modification : ", 20);
    print_number(st.st_mtime);
    write(1, "\n", 1);

    write(1, "Last status change : ", 21);
    print_number(st.st_ctime);
    write(1, "\n", 1);

    return 0;
}

