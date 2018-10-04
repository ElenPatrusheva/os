#include <stdio.h>
void reverse (char *str, char *rev)
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		rev[i] = str[n-i-1];
	}
	rev[n] = 0;
}
int main()
{
	printf("Enter the string: ");
	char str [200], revstr[200];
	gets(str);
	printf("The length of our string is: %d\n", strlen(str));
	char rev[200];
	reverse(str, rev);
	printf ("The reversed version is: %s\n", rev);
	return 0;
}
