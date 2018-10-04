#include <stdio.h>
#include <stdlib.h>

int main() {

	for (int i = 1; i<=3; i++){
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;
}
/*
init─┬─init───bash
     └─init───bash─┬─a.out─┬─a.out───a.out
                   │       └─a.out
                   └─pstree
*/