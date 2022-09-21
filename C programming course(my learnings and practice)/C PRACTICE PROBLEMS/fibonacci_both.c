#include <stdio.h>
//**************TWO RECURSION METHODS DEPENDING UPON THE STARTING VALE OF n***************

//METHOD 1
//int fibonacci(int n)
//{
//    if (n<2)
//    {
//        return 1;
//    }
//    return fibonacci(n-2)+fibonacci(n-1);   //this code will give correct result if we consider n to start from 0
//}

//METHOD 2
//int fibonacci(int n) 
//{
//    if (n==1 || n==2)
//    {
//        return (n-1);//Brackets can be skipped
//    }
//    return fibonacci(n-1)+fibonacci(n-2);//this will give accurate results if we consider the starting value of n to be 1
//}

//But both the methods will not display result for greater values of n like 50th term and other higher values
//ANY SOLUTION FOR THIS?

//***********************THREE ITERATIVE METHODS**********************


//METHOD1(when n starts from 0)
//int fibonacci(int n)
//{
//    int t1=0,t2=1,nextTerm;
//    for (int i = 1; i <= n; i++)
//    {
//        nextTerm=t1+t2;
//        t1=t2;
//        t2=nextTerm;
//    }
//    return t1;   //this will give correct result if starting value of n is 0
//}

//METHOD1(When n starts from 1)
int fibonacci(int n)
{
    int t1=0,t2=1,nextTerm;
    for (int i = 1; i < n; i++)
    {
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }
    return t1;//Many more such comnbinations can be made using appropriate logic and reasoning

}

//METHOD2(when n starts from 0)
//int fibonacci(int n)
//{
//    int t1=0,t2=1,sum;
//    if (n<=1)
//    {
//        return n;
//    }
//    for (int i = 2; i <=n; i++)
//    {
//        sum=t1+t2;
//        t1=t2;
//        t2=sum;
//    }
//    return t2;
//}


//METHOD2(when n starts from 1)
//int fibonacci(int n)
//{
//    int t1=0,t2=1,sum;
//    if (n<=2)
//    {
//        return (n-1);
//    }
//    for (int i = 3; i <=n; i++) //or i=2 and i<n(same meaning both)
//    {
//        sum=t1+t2;
//        t1=t2;
//        t2=sum;
//    }
//    return t2;
//}

//METHOD3(When n starts from 1)
//int fibonacci(int n)
//{
//    int a=0,b=1;
//    for (int i = 0; i < n-1; i++)
//    {
//         b=a+b;
//         a=b-a;
//    }
//    
//    return a;
//}


//METHOD3(when nstarts from 0)
//int fibonacci(int n)
//{
//    int a=0,b=1;
//    for (int i = 0; i < n; i++)//or i=1 and i<n+1 and many more such combinations are possible
//    {
//         b=a+b;
//         a=b-a;
//    }
//    
//    return a;
//}

int main()
{
    int n;
    printf("Enter the term of the fibonacci series you want the value\n");
    scanf("%d", &n);
    printf("The value of the %dth term of the fibonacci series is %d", n, fibonacci(n));
    return 0;
}