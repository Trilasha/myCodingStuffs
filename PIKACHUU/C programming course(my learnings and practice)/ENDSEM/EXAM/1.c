#include <stdio.h>
int main()
{
    FILE *fp;
    char var[30];
    fp=fopen("abc.txt","r");
    while (fgets(var,10,fp)!=EOF)
   printf("%c",var);
    
    return 0;
}