#ifndef DIRECTORY_H
#define DIRECTORY_H

typedef struct {
    char filename[256];
    int inodeNumber;
} DirectoryEntry;

void createRootDirectory();
void addDirectoryEntry(char *filename, int inodeNumber);
int findInodeByFilename(char *filename);

#endif // DIRECTORY_H