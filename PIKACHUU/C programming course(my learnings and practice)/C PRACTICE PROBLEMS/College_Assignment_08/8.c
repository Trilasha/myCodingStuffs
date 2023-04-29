//***Code for Q8***
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
int count_c=0;
int count_w=0;
    char ch;
    if ((fptr = fopen("myfile4.txt","r")) == NULL){
       printf("Not able to open this file");
       exit(1);
   }
   printf("---------------------------------------------------------------------------------------\n");
       printf("                  Reading the contents of the file(myfile4.txt)\n");
   printf("---------------------------------------------------------------------------------------\n");
   do {
        ch = fgetc(fptr);
      //  fputc(ch,fptr);
      printf("%c",ch);
      count_c++;
       if(ch==' ' || ch=='\n')
       count_w++;
           } while (ch != EOF);
           printf("\n");
   printf("-------------------------------------------------------------------------------------------\n");
           printf("             Counting the number of words and characters in the file(myfile4.txt)\n");
   printf("-------------------------------------------------------------------------------------------\n");
   printf("The total number of words is : %d\n",count_w);
   printf("The total number of characters(including spaces and null character) is : %d",count_c);
    fclose(fptr);
   return 0;}