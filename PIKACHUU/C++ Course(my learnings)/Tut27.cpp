//***********Member Friend Functions in C++*****************
//Individually declaring functions as the friends
#include <iostream>
using namespace std;
//Forward declaration...1
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumrealcomplex(Complex, Complex); //...2(just simply declared)
    int sumcomcomplex(Complex, Complex);
};


class Complex
{
    int a, b;
    friend int Calculator ::sumrealcomplex(Complex o1, Complex o2); //Made Calculator class its friend so that private data can be accessed
    friend int Calculator ::sumcomcomplex(Complex o1, Complex o2);

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void setPrintnumber()
    {
        cout << "The complex number is " << a << " + " << b << "i" << endl;
    }
};



int Calculator ::sumrealcomplex(Complex o1, Complex o2) //...3(defined)
{
    return (o1.a + o2.a);
}

int Calculator ::sumcomcomplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}



int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumrealcomplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumcomcomplex(o1, o2);
    cout << "The sum of the complex part of o1 and o2 is " << resc << endl;
    return 0;
}

//so what we have actually done is that
//-->we have made only one function of one class(i.e,Calculator)the friend of another class(i.e,Complex) so that the private data can be accessed
//--->In the similar way,many more functions of the class Calculator can be made the friend of the class Complex
//But that repetitive thing can be avoided if the entire class is made the friend
//-->For that we have done FORWARD DECLARATION of the class whose private data is going to be used(i.e,Complex in this case)
//-->Since in the forward declaration we only stated that a class called Complex exists and mentioned nothing about its objects,
//so that function of Calculator(using the complex objects)has to be declared first and then define3d later after the Complex class
//-->Also The Calculator class has to be defined and declared first before Complex