#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("not funny");
        return 1;
    }

    const char* filename = argv[1];
    struct stat file_stat;

    if (stat(filename, &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    printf("File: %s\n", filename);
    printf("Inode: %lu\n", file_stat.st_ino);
    printf("Number of Hard Links: %lu\n", file_stat.st_nlink);
    printf("UID: %d\n", file_stat.st_uid);
    printf("GID: %d\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Block Size: %ld bytes\n", file_stat.st_blksize);
    printf("Number of Blocks: %lld\n", (long long) file_stat.st_blocks);

    printf("Time of Last Access: %ld\n", file_stat.st_atime);
    printf("Time of Last Modification: %ld\n", file_stat.st_mtime);
    printf("Time of Last Change: %ld\n", file_stat.st_ctime);

    return 0;
}

