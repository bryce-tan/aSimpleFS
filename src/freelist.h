#ifndef FREELIST_H
#define FREELIST_H

void initializeFreelist();
int allocateBlock();
void freeBlock(int blockNumber);
void writeFreelist();
void readFreelist();

#endif // FREELIST_H