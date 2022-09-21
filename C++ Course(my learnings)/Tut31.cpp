//********CONSTRUCTOR OVERLOADING IN C+=************
//-->There can be multiple constructors used inside one class(this is what is called constructor overloading)
//-->Depending upon our input,the preferred constructor will work
#include <iostream>
using namespace std;
class Complex
{
    int x,y;
    public:
    Complex()//Constructor_01(default)
    {
        x=0;
        y=0;
    }
    Complex(int a)//Constructor_02(parameterised)
    {
        x=a;
        y=0;
    }
    Complex(int a,int b)//Constructor_03(parameterised)
    {
        x=a;
        y=b;
    }
    void printNumber()
    {
        cout<<"The entered complex number is "<<x<<" + "<<y<<"i"<<endl;
    }
};
int main()
{
    Complex c1;
    c1.printNumber();
    Complex c2(3,4);
    c2.printNumber();
    Complex c3(9);
    c3.printNumber();

    return 0;
}
