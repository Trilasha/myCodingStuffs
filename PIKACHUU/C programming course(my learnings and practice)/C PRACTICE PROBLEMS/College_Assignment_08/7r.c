//***Code for Q7***//This code also displays a question mark-->why?
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;
    FILE *fptr1;
    FILE *fptr2;
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
   //ch=fgetc(fptr1);
   while (ch!=EOF)
   {
       ch=fgetc(fptr1);
       fputc(toupper(ch),fptr2);
   }
   printf("All the contents of myfile1.txt have been converted to uppercase and written in the output.txt file.");
   fclose(fptr1);
   fclose(fptr2);
    return 0;
}

//DO ANALYSIS AND FIND OUT THE REASON
//do {
//      ch = fgetc(fptr1);
//     // ch = toupper(ch); //with this line,program does not run
//      fputc(toupper(ch), fptr2);//with line a "?"appears at the end in the output.txt file
//   } while (ch != EOF);