//************Constructors in C++***********
#include <iostream>
using namespace std;
class Complex
{
    int a,b;
    public:
    //Creating a Constructor
    //Constructor is a special member function with the same name as the class
    //-->SAME NAME IS IMPORTANT BECAUSE Constructor itself has no return type but when it's a member function then it must have a return type
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created(only because it has the same name as the class)

    Complex(void);//Constructor DECLARATION

    void printnumber()
    {
        cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
    }
};
Complex ::Complex(void)//Constructor DEFINITION//-->This is a default constructor as it has no parameters
{
a=10;
b=20;
}

int main()
{
    Complex c1,c2,c3;
    c1.printnumber();
    c2.printnumber();
    c3.printnumber();
    return 0;
}
/*
//CHARACTERISTICS OF CONSTRUCTORS
-->It should be declared in tht public section of the class
-->They are automatically invoked whenever the object is created
-->They cannot return values and do not have return types
-->It can have default arguments,like,Complex::Complex(void,int a=9)
-->We cannot refer to their address
*/