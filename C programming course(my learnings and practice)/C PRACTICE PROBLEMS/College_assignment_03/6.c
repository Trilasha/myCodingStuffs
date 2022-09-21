//***Code for Q6***-->MODIFIED
#include <stdio.h>
int main()
{
    int num,original_num,reversed=0;
    printf("Enter a number:\n");
    scanf("%d",&num);
    //First we will reverse the entered number
    //After that the while and switch case will be applied on the reversed number to print it in words
    original_num=num;
    while (num)
    {
        reversed=reversed*10 +num%10;
        num=num/10;
    }
   printf("%d = ",original_num);
while (reversed)
{
    switch (reversed%10)
    {
    case  0:
        printf("zero ");
        break;
     case  1:
        printf("one ");
        break;
         case  2:
        printf("two ");
        break;
         case  3:
        printf("three ");
        break;
         case  4:
        printf("four ");
        break;

         case 5:
        printf("five ");
        break;
         case  6:
        printf("six ");
        break;
         case  7:
        printf("seven ");
        break;
         case  8:
        printf("eight ");
        break;
         case  9:
        printf("nine ");
        break;
    }
    reversed/=10;
}
//-->
   if(original_num%10==0) 
   printf("zero");
    
    return 0;
}