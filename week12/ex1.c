#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){

	unsigned char buffer[20];
	buffer[20] = 0;
	int fd = open("/dev/random", O_RDONLY);
	if( fd != -1 ) {
		read( fd, buffer, 20);
		close(fd);
		FILE *my_file = fopen("ex1.txt", "w");
		for (int i = 0; i < 20; i++){
			buffer[i] = (buffer[i] % 94) + 33;//only symbol that seems like string 
		}
		fprintf(my_file, "%s", buffer);
		close(my_file);
		printf( "%s\n", buffer );
	} else {
		exit( 1 );
	}
	return 0;
}