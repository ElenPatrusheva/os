#include <stdio.h>
int main()
{
	int n;
	printf ("Enter the number: ");
	char str[200];
	scanf("%d", &n);
	for (int i = 0; i < 2*n-1; i++)
	{
		str[i]=' ';
	}
	str[2*n-1] = 0;
	for (int i = 0; i < n; i++)
	{
		str[n-i-1] = '*';
		str[n-1+i] = '*';
		printf(str);
		printf("\n");
	}

	return 0;
}
