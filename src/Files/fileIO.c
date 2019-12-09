#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fileIO.h"



size_t fileSize(int fd, int *error) {
  struct stat sb;  
  if (fstat(fd, &sb) == -1) *error = -1;
  
  return  sb.st_size;
}



void writeFile(const char *fileDir, char *data)
{
    // Open file
    int file = open(fileDir, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    // Get file Size
    size_t size = strlen(data);

    if (ftruncate(file, size)) perror("ftruncate");  // truncate file length

    // Mapping memory directly to the cpu
    char *fileMap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file, STDIN_FILENO);

    // Write data, and close file
    memcpy(fileMap, data, size);  
    // write();
    munmap(fileMap, size);
    close(file);
}


int readFile(const char *fileDir, char **data)
{
    int error = 0;

    // Open file
    int src = open(fileDir, O_RDONLY);

    // Get file Size
    size_t size = fileSize(src, &error);
    if (error == -1) return -1;
    char *tmpData = (char*)malloc(sizeof(char) * size + 1);

    // Mapping memory directly to the cpu
    char *srcMap = mmap(NULL, size, PROT_READ, MAP_PRIVATE, src, STDIN_FILENO);

    // read data and close file
    memcpy(tmpData, srcMap, size);
    *data = tmpData;
    munmap(srcMap, size);
    close(src);
    remove(fileDir);

    return EXIT_SUCCESS;
}