#include <stdio.h>
void bubblesort (int *array, int n){
	int k = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n - 1 - i; j++){
			if (array[j] > array[j+1]){
				k = array[j];
				array[j] = array[j+1];
				array[j+1] = k;
			}
		}
	}
}
int main(){
	int array[200], n;
	printf("Enter the number of integers: ");
	scanf("%d", &n);
	printf("Enter an array integer: ");
	for (int i = 0; i < n; i++){
		scanf ("%d", &array[i]);
	}
	bubblesort(&array, n);
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}	
	return 0;
}
