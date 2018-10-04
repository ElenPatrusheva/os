#include <stdio.h>
void regular(int n)
{
	char str[200];
	for (int i = 0; i < 2*n+1; i++)
	{
		str[i] = ' ';
	}
	str[n] = 0;
	for (int i = 0; i < n; i++)
	{
		str[n-1-i] = '*';
		str[n+i-1] = '*';
		printf(str);
		printf("\n");
	}
}
void right(int n)
{
	char str[200];
	for (int i = 0; i < n; i++)
	{
		str[i] = ' ';
	}
	str[n] = 0;
	for (int i = 0; i < n; i++)
	{
		str[i] = '*';
		printf(str);
		printf("\n");

	}
}
void rect(int n)
{
	char str[200];
	for (int i = 0; i < n; i++)
	{
		str[i] = '*';
	}
	str[n] = 0;
	for (int i = 0; i < n; i++)
	{
		printf(str);
		printf("\n");
	}
}
void scelet(int n)
{
	char str[200];
	for (int i = 0; i < n+1; i++)
	{
		str[i] = ' ';
	}
	str[n] = 0;
	str[n+1] = '\n';
	for (int i = 0; i < n; i++)
	{
		str[i] = '*';
		printf(str);
		printf("\n");

	}
	for (int i = n-1; i>0; i--)
	{
		str[i] = ' ';
		printf(str);
		printf("\n");

	}
}
void draw_figure(int n, int ty)
{
	switch(ty)
	{
		case 1:
			regular(n);
			break;
		case 2:
			right(n);
			break;
		case 3:
			rect(n);
			break;
		case 4:
			scelet(n);
			break;
	}
}
int main()
{
	printf("Enter your number: ");
	int n, ty;
	scanf ("%d", &n);
	printf ("Enter number to choose a type of a figure\n1 - regular triangle, 2 - right triangle, 3 - rect, 4 - isoscelet triangle\n");
	scanf ("%d", &ty);
	while (ty < 1 || ty > 4)
	{
		printf("There is no figure of the type %d, please, choose the correct type", ty);
		sscanf("%d", &ty); 
	}
	draw_figure (n, ty);
	return 0;
}
