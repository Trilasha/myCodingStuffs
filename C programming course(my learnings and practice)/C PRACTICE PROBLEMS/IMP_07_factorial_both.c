#include <stdio.h>
//int factorialLoop(int a)
//{
//    int val = 1;
//    for (int i = a; i >= 1; i--)
//    {
//        val *= i;
//    }
//    return val;
//}

int factorialRec(int a)
{
if (a==1 || a==0)
{
   return 1;
}
else
{
return (a*factorialRec(a-1));
}


}

int main()
{
    int a;
    printf("Enter the number you want factorial of\n");
    scanf("%d", &a);
    printf("The factorial of %d is %d", a, factorialRec(a));


    return 0;
}