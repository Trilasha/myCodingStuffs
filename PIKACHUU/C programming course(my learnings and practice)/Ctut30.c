/* 
Take input from the user and ask userto choose 0 for triangular star pattern and 1 for reversed triangular star pattern
then print the pattern accordingly
*
**
***
**** ->Triangular Star Pattern

****
***
**
*->Reversed Triangular Star Pattern
*/

#include <stdio.h>
int main()
{
    
    int s;
    printf("Press 0 for triangular star pattern and 1 for reversed triangular star pattern\n");
    scanf("%d", &s);
switch (s)
{
case 0:
   printf("*\n");
    printf("**\n");
     printf("***\n");
      printf("****\n");
      break;

      case 1:
   printf("****\n");
    printf("***\n");
     printf("**\n");
      printf("*\n");

    break;

default:
    break;
}
    
    //Code copied from the comment section

    int num,a=1,b=2,c;
    printf("Enter the number of Star(*) pattern\n");
    scanf("%d", &num);
    printf("Choice to shape of pattern=\n 1.Triangular pattern \n 2.Reversed Triangular pattern \n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
      for (int i = 0; i <= num; i++)
      {
        for (int j = 0; j <i; j++)
        {
            printf("*");
        }
        printf("\n");
        
      }
      
        break;

        case 2:                    //Not understood
      for (int i = 0; i <= num; i++)
      {
        for (int j = i; j <num; j++)
        {
            printf("*");
        }
        printf("\n");
        
      }
      
        break;
    
    default:
    printf("Wrong choice entered\n");
        break;
    }


    return 0;

}
//Solution by Harry Sir given in Ctut33.c
