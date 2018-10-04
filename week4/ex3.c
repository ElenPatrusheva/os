#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16
#define TERMINATE_STR "exit()"
int main() {
	printf ("String for termination is: exit()\n");
	char input_str[BUFFER_SIZE];
	while (1){
		printf(">> ");
		scanf ("%s", input_str);
		if (!strcmp (input_str, TERMINATE_STR)){
			return 0;
		}
		else{
			system(input_str);
		}
	}
}