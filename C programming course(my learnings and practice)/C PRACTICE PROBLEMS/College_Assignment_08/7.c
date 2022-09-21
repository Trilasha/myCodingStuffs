//***Code for Q7***????????Runs into infinite loop
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
int main()
{
FILE *fptr1;
FILE  *fptr2;
   char ch;
 //clrscr();
 
   fptr1 = fopen("myfile1.txt", "r");
   if (fptr1 == NULL) {
      puts("Not able to open this file");
      exit(1);
   }
 
   fptr2 = fopen("output.txt", "w");
   if (fptr2 == NULL) {
      puts("Not able to open this file");
     fclose(fptr1);
      exit(1);
   }
 
   do {
      ch = fgetc(fptr1);
      ch = toupper(ch);
      fputc(ch, fptr2);
   } while (ch != EOF);
  
   printf("All the contents of myfile1.txt has been converted to uppercase and written in the output.txt file.");
   fclose(fptr1);
   //fclose(fptr2);
 //  fcloseall(); Why is it showing implicit declaration?
  // getch();
}