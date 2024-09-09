#ifndef INODE_H
#define INODE_H

#define DIRECT_POINTERS 12

typedef struct {
    int size;
    int blockPointers[DIRECT_POINTERS];  // Pointers to data blocks
    int indirectPointer;    // Pointer to indirect blocks
    int isAllocated;
} Inode;

int allocateInode();
void freeInode(int inodeNumber);
void readInode(int inodeNumber, Inode *inode);
void writeInode(int inodeNumber, Inode *inode);

#endif // INODE_H