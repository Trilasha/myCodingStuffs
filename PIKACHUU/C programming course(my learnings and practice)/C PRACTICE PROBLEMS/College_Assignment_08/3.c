//***Code for Q3***
#include <stdio.h>
#include <stdlib.h>
int main()
{
   char ch; 
   FILE *source, *target;
   char source_file[] = "myfile1.txt";
   char target_file[] = "myfile2.txt";
   source = fopen(source_file, "r");
   if (source == NULL)
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   target = fopen(target_file, "w");
   if (target == NULL)
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE); // Same as exit(1)
   }
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
   printf("The contents of myfile1.txt have been successfully copied to myfile2.txt\n");
   fclose(source);
   fclose(target);
   return 0;
}