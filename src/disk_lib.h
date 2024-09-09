#ifndef DISK_LIB_H
#define DISK_LIB_H

#include <fcntl.h>    // for open()
#include <unistd.h>   // for read(), write(), lseek(), fsync()
#include <stdio.h>    // for perror()
#include <sys/stat.h> // for file modes
#include <string.h>   // for memset

#define BLOCK_SIZE 4096

// Function to open the disk (file) or create it if it doesn't exist
int openDisk(char *filename, int nbytes);

// Function to read a 4-KB block from the disk
int readBlock(int disk, int blocknr, void *block);

// Function to write a 4-KB block to the disk
int writeBlock(int disk, int blocknr, void *block);

// Function to sync the disk to ensure all writes are flushed
void syncDisk(int disk);

#endif // DISK_LIB_H