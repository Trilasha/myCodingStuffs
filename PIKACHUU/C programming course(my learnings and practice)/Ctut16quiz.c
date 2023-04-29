#include <stdio.h>

int main()
{
   //1 to convert celsius into fahrenheit(converter)


int a, b, c, num;
   printf("Enter the temperature in celsius\n");
   scanf("%d", &a);

   printf("The corresponding value of %d celsius in F is\n", a);
   printf("%d\n", 9*a/5+32);






   //2 to make a calculator using switch statement

printf("Enter the first number\n");
scanf("%d", &b);
printf("Enter the second number\n");
scanf("%d", &c);

printf("Which operation do you want to perform:-\n Press 1)Addition\n 2)Subtraction\n 3)Multiplication\n 4)Division\n");
scanf("%d", &num);

switch (num)
{
case 1:
    printf("The sum is %d", b+c);
    break;
    case 2:
    printf("The difference is %d", b-c);
    break;
    case 3:
    printf("The product is %d", b*c);
    break;
    case 4:
    printf("The quotient is %d", b/c);
    break;

default:
printf("No results found");
    break;
}

return 0;
}
