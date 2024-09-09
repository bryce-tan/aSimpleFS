# include "disk_lib.h"

int openDisk(char *filename, int nbytes){
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1){
        perror("openDisk: Failed to open file");
        return -1;
    }
    
    if (ftruncate(fd, nbytes) == -1){
        perror("openDIsk: Failed to set file size");
        return -1;
    }
    return fd;
}

int readBlock(int disk, int blocknr, void *block){
    off_t offset = blocknr * BLOCK_SIZE;
    if (lseek(disk, offset, SEEK_SET) == -1){
        perror("readBlock: Failed to seek offset");
        return -1;
    }

    if (read(disk, block, BLOCK_SIZE) != BLOCK_SIZE){
        perror("readBlock: Failed to read block");
        return -1;
    }

    return 0;
}

int writeBlock(int disk, int blocknr, void *block){
    off_t offset = blocknr * BLOCK_SIZE;
    if (lseek(disk, offset, SEEK_SET) == -1){
        perror("writeBlock: Failed to seek offset");
        return -1;
    }

    if (write(disk, block, BLOCK_SIZE) != BLOCK_SIZE){
        perror("writeBlock: Failed to write block");
        return -1;
    }

    return 0;
}

void syncDisk(int disk){
    if (fsync(disk) == -1)
    {
        perror("syncDisk: Failed to sync");
    }
    
}