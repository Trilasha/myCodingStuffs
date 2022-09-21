#include <stdio.h>

void starPattern(int rows)
{
for (int i = 0; i < rows; i++)
{ 
    for (int j = 0; j <= i; j++)
{
   printf("*");
}
printf("\n");
    
}

return;
}



void reversedstarPattern(int rows)
{
for (int i = 0; i < rows; i++)
{ 
    for (int j = 0; j <= rows-i-1; j++)
{
   printf("*");
}
printf("\n");
    
}

return;
}





int main()
{
    int rows, type;
    printf("Enter 0 for triangular star pattern and 1 for reversed triangular star pattern\n");
    scanf("%d", &type); 
    printf("How many rows do you want?\n");
    scanf("%d", &rows); 
                             //We have used a function and called it by value so that it can be used many times
   switch (type)
   {
   case 0:
     starPattern(rows);
       break;
   
    case 01:
     reversedstarPattern(rows);
       break;
   

   default:
   printf("Sorry!You have entered an invalid choice\n");
       break;  //Line nos.58 and 59 can be skipped
   }
    return 0;
}