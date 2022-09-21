//***Code for Q1***
#include <stdio.h>
#include <stdlib.h>//used for the exit funtion solely
int main()
{
    FILE *fptr;
    char ch;
    if ((fptr = fopen("myfile1.txt", "r")) == NULL)
    {
        printf("Not able to open this file");
        exit(1);//terminated with error  whereeas exit(0)-->successful termination,i.e,without errors
    }
    printf("           Reading the contents of the file(myfile1.txt)\n");                               // Any alternative way to do the same using char str[] and fgets()?
    printf("--------------------------------------------------------------------\n\n");
    do
    {
        ch = fgetc(fptr);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(fptr);
    return 0;
}