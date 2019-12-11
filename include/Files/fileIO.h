#ifndef FILE_IO_H
#define FILE_IO_H


void dirCreate(const char *dir);
void writeFile(const char *dir, const char *name, char *data);
int readFile(const char *fileDir, char **data);

#endif // FILE_IO_H