//***I solved it myself:)


#include <stdio.h>
int main()
{
    //Taking the input from the user
    int a,b;
    printf("Enter the number whose multiplication table you want to print\n");
    scanf("%d", &a);
    printf("How many multiples of %d do you want to print(starting from firat natural number)?\n", a);
    scanf("%d", &b);
    printf("The multiplication table of %d is given below:\n", a);
    for (int i = 1; i < b+1; i++)
    {
        printf("%d X %d = %d\n", a,i,a*i);//Or else keeping initially i=0, same result can be obtained by writing i+1 in printf
    }
    
    return 0;
}