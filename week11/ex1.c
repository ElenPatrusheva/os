#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

int main(){
    struct stat status;


    int file_open = open("ex1.txt", O_RDWR);

    if (file_open < 0){
        perror("file is not available to open");
        return 0;
    }

    size_t file_size = (size_t)status.st_size;
    char text[] = "This is a nice day";
    if (file_size < strlen(text) ){
        file_size = strlen(text);
    }

    char * map = (char*)(long)(mmap(0, file_size, PROT_READ| PROT_WRITE, MAP_SHARED, file_open, 0));
    if(map == MAP_FAILED){
        perror("Impossible to map file");
        return 0;
    }

    memset(map, ' ', file_size);
    strcpy(map, text);
    map[strlen(text)] = ' ';
    munmap(map, file_size);

    return 0;
}
