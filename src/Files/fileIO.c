#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fileIO.h"



void dirCreate(const char *dir) {
    struct stat st = { 0 };

    if (stat(dir, &st) == -1) {
        int rc = mkdir(dir, 0700);
        if (rc == -1) {
            perror("mkdir");
        }
    }
}


size_t fileSize(int fd, int *error) {
  struct stat sb;  
  if (fstat(fd, &sb) == -1) *error = -1;
  
  return  sb.st_size;
}



void writeFile(const char *dir, const char *name, char *data)
{
    char *fCreate = (char*)malloc(sizeof(char) * (strlen(dir) + strlen(name)));
    sprintf(fCreate, "%s/%s", dir, name);

    // Open file
    int fdWrite = open(fCreate, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    // Get file Size
    size_t size = strlen(data);

    if (ftruncate(fdWrite, size)) perror("ftruncate");  // truncate file length

    // Mapping memory directly to the cpu
    char *fileMap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fdWrite, STDIN_FILENO);

    // Write data
    memcpy(fileMap, data, size);  

	// Close file
    munmap(fileMap, size);
    close(fdWrite);
}


/**
 * Read an existing file.
 * - Opens a file and returns it's file discriptor. 
 * - Find's the length of the file.
 * - Store memory directly to the cpu.
 * - Copy file data to temp data. Get data from
 *  *tempData and 
 * 
 * @param ptr_fileDir, the location of the file.
 * @param double_ptr_data, gets the data stored in
 * 		  the file. Store *tempData in **data.
 * @return 0 if file can be read,  
 *         otherwise -1 for failure.
 */
int readFile(const char *fileDir, char **data)
{
    int error = 0;

    // Open file
    int fdRead = open(fileDir, O_RDONLY);

    // Get file Size
    size_t size = fileSize(fdRead, &error);
    if (error == -1) return -1;
    char *tmpData = (char*)malloc(sizeof(char) * size + 1);

    // Mapping memory directly to the cpu
    char *fdReadMap = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fdRead, STDIN_FILENO);

    // Copy file data to temp data
    memcpy(tmpData, fdReadMap, size);
    *data = tmpData;
    
	// Close and remove file
    close(fdRead);
	munmap(fdReadMap, size);
    remove(fileDir);

    return EXIT_SUCCESS;
}
