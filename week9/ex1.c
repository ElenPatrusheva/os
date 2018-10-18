#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1;
#define false 0;

struct Page_frame {
	int page_n;
	int p_frame;
};

void printer(struct Page_frame *buffer, int used_n){
	for (int i = 0; i < used_n; i++){
		printf ("%d: ",buffer[i].page_n);
		int a = buffer[i].p_frame;
		printf("%d\n", a);

	} 
	printf("\n");

}
int update(struct Page_frame *buffer, int next_i, int *used_n, int frames_n){
	int min = 256;
	int min_i = 0;
	for (int i = 0; i < *used_n; i++){
		if (buffer[i].p_frame < min){
			min = buffer[i].p_frame;
			min_i = i;
		}   
	}
	int hit = false;

	for (int i = 0; i < *used_n; i++){
		if (buffer[i].page_n == next_i) {
			buffer[i].p_frame = buffer[i].p_frame / 2;
			buffer[i].p_frame = buffer[i].p_frame + 128;
			hit = true;
		} else {
			buffer[i].p_frame = buffer[i].p_frame / 2;
		}
	}

	if (hit) return hit;
	if (*used_n < frames_n){
		struct Page_frame tmp;
		tmp.page_n = next_i;
		tmp.p_frame = 128;
		buffer[*used_n] = tmp;
		*used_n += 1;
	} else {
		buffer[min_i].page_n = next_i;
		buffer[min_i].p_frame = 128;
	}
	return false;
}

int main () {
	char ch;
	int frames_n = 0;
	int hit_n = 0;
	int miss_n = 0;
	printf("Enter the number of page frames: ");
	scanf("%d", &frames_n);
	int used_n = 0;
	int next_i=0;
 

	FILE *input_file;
	input_file = fopen("input_file.txt", "r");
	struct Page_frame * buffer = malloc (frames_n * sizeof(struct Page_frame));
	while (fscanf(input_file, "%d", &next_i) == 1) {
		int status = update(buffer, next_i, &used_n, frames_n);
		if (status) {
			hit_n++;
		} else {
			miss_n++;
		}
		//printer(buffer, used_n);
	}
	float hit_rate = (float)hit_n / (float)(hit_n + miss_n);
	float miss_rate = (float)miss_n / (float)(hit_n + miss_n);
	printf("Hit number is: %d\nMiss number is: %d\nHit ratio is: %lf\nMiss ratio is: %lf\n", hit_n, miss_n, hit_rate, miss_rate);
	return 0;
}
