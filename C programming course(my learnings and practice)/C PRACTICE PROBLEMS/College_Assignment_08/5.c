//***Code for Q5***
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;

    char ch;
    if ((fptr = fopen("myfile1.txt","r")) == NULL){
       printf("Not able to open this file");
       exit(1);
   }
   printf("           Reading a stream of characters from the file->myfile1.txt)\n");
   printf("------------------------------------------------------------------------------\n\n");
    do {
        ch = fgetc(fptr);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(fptr);
   return 0;
}