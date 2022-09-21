//***Code for Q9***
#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void function(char *a, int s, int t)
{
int i;
if (s == t)
	printf("%s\n", a);
else
{for (i = s; i <= t; i++)
	{
		swap((a+s), (a+i));
		function(a, s+1, t);
		swap((a+s), (a+i)); 
	}
}}
int main()
{
	char str[40];
    printf("Enter a string:\n");
    gets(str);
	int n = strlen(str);
    printf("All the possible permutations of the above entered string:\n");
	function(str, 0, n-1);
	return 0;}
