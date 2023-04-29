//Recursions and printing fabonacci series
#include <iostream>
using namespace std;



int fabo(int b)
{
    if (b<2)
    {
        return 1;
    }
    else
    return fabo(b-1)+fabo(b-2);
}




int factorial(int a)
{
    if (a==1 || a==0)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}



int main()
{
int a,b;
cout<<"Enter the number that you want factorial of : "<<endl;
cin>>a;
cout<<"The factorial of "<<a<<" is "<<factorial(a)<<endl;

cout<<"Enter the term of the fibonacci series that you want to see the value of : "<<endl;
cin>>b;
cout<<"The value of "<<b<<"th term of the fibonacci series is "<<fabo(b)<<endl;


    return 0;
}