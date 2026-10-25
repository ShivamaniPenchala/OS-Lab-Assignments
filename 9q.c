#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    stat(argv[1], &st);
    
    printf("Inode : %d\n", st.st_ino);
    printf("Hard links : %d\n", st.st_nlink);
    printf("UID : %d\n", st.st_uid);
    printf("GID : %d\n", st.st_gid);
    printf("Size : %d Bytes \n", st.st_size);
    printf("Block size  : %d Bytes \n", st.st_blksize);
    printf("Blocks : %d\n", st.st_blocks);
    printf("Last access : %d\n", st.st_atime);
    printf("Last modification : %d\n", st.st_mtime);
    printf("Last status change : %d\n", st.st_ctime);

    return 0;
}
