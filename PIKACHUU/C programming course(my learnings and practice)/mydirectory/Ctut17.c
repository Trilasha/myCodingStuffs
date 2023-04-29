#include <stdio.h>


int main()

{
   /*  label:
    printf("We are inside label now\n");    //my goto is not ending can't find the error....
    goto end;
    printf("Hello  World\n");
    goto label;
    end:
    printf("We are at the end"); 
    */


  // Another way to use goto command    //I am unable to run this program
int i,j,num;
  for (i = 0; i < 8; i++)
  {
      printf("%d", i);
      for (int j = 0; j < 8; j++)
      {
      printf("Enter the number. enter 0 to exit\n");
      scanf("%d", &num);
      }
      
  }
  

    return 0;
}
