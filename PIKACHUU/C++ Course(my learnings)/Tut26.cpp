//****************FRIENDS FUNCTIONS IN C++*************
//The same thing has been done in the previous tutorial but without making friends
#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    friend Complex sumComplex(Complex o1,Complex o2);//Even without o1 and o2,it will remain correct//Now Complex has made sumComplex(which is not a part of the classs Complex)its friend so that it can now access its private data
    void printNumber()                               //Making friends does not mean that sumComplex is now a member of the Complex class
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
    };

    Complex sumComplex(Complex o1, Complex o2)
    {
        Complex o3;
        o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
        return o3;
    }


int main()
{
    Complex c1, c2, sum;
    c1.setNumber(1, 3);
    c1.printNumber();

    c2.setNumber(5, 7);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}
/*
*******PROPERTIES OF FRIEND FUNCTIONS
-->Not in the scope of the class
-->since it is not in the scope of the class,it cannot be called from the object of that class like c1.setComplex()==invalid
-->can be invoked without the help of any object
-->usually contains the objects as the arguments
-->can be declared inside the public or private section of the class
-->it cannot access the members directly by their names and need object_name.member_name to access any member
*/