#include "inode.h"
#include "disk_lib.h"
#include <stdio.h>
#include <string.h>

Inode inodeTable[NUM_INODES];

int allocateInode(){
    for (int i = 0; i < NUM_INODES; i++){
        if (inodeTable[i].isAllocated == 0){
            inodeTable[i].isAllocated = 1; // Initialize the inode
            inodeTable[i].size = 0;
            inodeTable[i].indirectPointer = -1;
            for (int j = 0; j < DIRECT_POINTERS; j++){
                inodeTable[i].blockPointers[j] = -1;
            }
            writeInode(i, &inodeTable[i]); // Persistent the inodes
            return i;
        }
    }
    return -1; // No free inode
}

int freeInode(int inodeNumber){
    if (inodeNumber < 0 || inodeNumber >= NUM_INODES){
        printf("freeInode: Invalid inode number\n");
        return;
    }
    inodeTable[inodeNumber].size = 0;
    inodeTable[inodeNumber].isAllocated = 0;
    inodeTable[inodeNumber].indirectPointer = -1;
    for (int j = 0; j < DIRECT_POINTERS; j++){
        inodeTable[inodeNumber].blockPointers[j] = -1;
    }
    writeInode(inodeNumber, &inodeTable[inodeNumber]);
}