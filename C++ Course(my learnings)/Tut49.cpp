//*******Initialization List in Constructors in C++*******
#include <iostream>
using namespace std;
/*
Syntax for initialization list in constructor:
constructor (argument-list) : initialization -section
{
    assignment + other code;
}

*/
class Test
{
    int a, b;

public:
    // Test(int i,int j) : a(i), b(j)
    // Test(int i,int j) : a(i), b(i+j)
    // Test(int i,int j) : a(i), b(2*j)
    //Test(int i,int j) : a(i), b(a+j)
    //Test(int i,int j) : b(j), a(i+b)//-->will show an error because a will be initialized first since a is declared first than b
    //-->The solution is to write int b,a; i.e,b must be declared before a

    //Test(int i,int j): b(i)
    //{
    //    a=j;
    //    cout<<"Constructor executed"<<endl;
    //    cout<<"Value of a is "<<a<<endl;
    //    cout<<"Value of b is "<<b<<endl;

    //}

    // Test(int i,int j): a(i)
    //{
    //   // b=i+j;
    //   b=a+j;
    //    cout<<"Constructor executed"<<endl;
    //    cout<<"Value of a is "<<a<<endl;
    //    cout<<"Value of b is "<<b<<endl;
    //
    //}

    Test(int i, int j) : b(j) //gives correct result even on for b(i)
    {
        //a=i+j;
        a = i + b;
        cout << "Constructor executed" << endl;
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
    }
    // Test(int i,int j)
    //{
    //    b=i;                  //the most general one-->a=i;b-j;
    //    a=j;
    //    cout<<"Constructor executed"<<endl;
    //    cout<<"Value of a is "<<a<<endl;
    //    cout<<"Value of b is "<<b<<endl;
    //
    //}
};
int main()
{
    Test t1(4, 6);
    return 0;
}