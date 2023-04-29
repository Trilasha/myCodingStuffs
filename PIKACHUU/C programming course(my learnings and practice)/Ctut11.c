#include <stdio.h>

// this progam also includes another variable marks to explain nested switch condition

int main()
{
    int age;
    int  marks;

    printf("Enter your age\n");
    scanf("%d", &age);

    printf("Enter your marks\n");
    scanf("%d", &marks);



switch (age)
{
case 3:
    printf("The age is 3\n");

    // here goes the nested switch

    switch (marks)      
    {
    case 45:
        printf("Your marks are 45");
        break;
    
    default:
    printf("Your marks are not 45");
        break;
    }


    break;

case 13:
    printf("The age is 13\n");
 break;

case 23:
    printf("The age is 23\n");
   //break;     // this step shows the consequence of not giving break


default:
printf("Age is nither 3 nor 13 nor 23\n");
    break;
}

    return 0;
}
