#include <stdio.h>

int main(int argc, char *argv[]) {

	int PID = fork();
	int n = 276;
	if (PID == 0){
		printf("hello from child[%d - %d]\n", getpid(), n);
	}
	else if (PID > 0){
		printf("hello from parent[%d - %d]\n", getpid(), n);
	}
	else {
		return 1;
	}
	return 0;
}