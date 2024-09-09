#ifndef FILESYSTEM_H
#define FILESYSTEM_H

void createFile(char *filename);
void deleteFile(char *filename);
void writeFile(char *filename, char *data, int size);
void readFile(char *filename, char *buffer, int size);

#endif // FILESYSTEM_H