//***Code fo Q4***
#include <stdio.h>
int main ()
{
  FILE * fptr;
  int i,n;
  char str[100];
  char str1;
  
    printf("***Write multiple lines in a text file***\n");
	printf("------------------------------------------------------------\n");   
	printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
	printf("\n :: The lines are ::\n");
	fptr = fopen ("myfile3.txt","w"); 
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
        fputs(str, fptr);
		}
  fclose(fptr);
  return 0;
}