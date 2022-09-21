//*****************Parameterized and Default Constructors in C++******************8
#include <iostream>
using namespace std;
class Complex
{
    int a,b,c;
    public:
    Complex(){};
    Complex(int,int);//constructor declaration
    void printnumber()
    {
        cout<<"Your entered complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
};
Complex::Complex(int x,int y)//-->This is called a parameterized constructor as it takes 2 parameters
{
    a=x;
    b=y;
}
int main()
{
    //There are two ways of calling them
    
    //1-->Implicit Call
    Complex a(4,5);
    //Explicit Call
    Complex b=Complex(7,3);
    a.printnumber();
    b.printnumber();
    Complex c;//For this format,a default constructor must be created 
    c=Complex(1,9);
    c.printnumber();
    return 0;
}