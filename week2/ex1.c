#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("maximum int is : %d\n", a);
	printf("its size is: %d bytes\n", sizeof(a));
	printf("maximum float is : %f\n", b);
	printf("its size is: %d bytes\n", sizeof(b));
	printf("maximum double is : %f\n", c);
	printf("its size is: %d bytes\n", sizeof(c));
	return 0;
}
