//**************Doing the previous program but now by making the entire class as a friend********************
#include <iostream>
using namespace std;
class Complex;

class Calculator
{
public:
int sumOfreal(Complex,Complex);
int sumOfcomp(Complex,Complex);
};

class Complex
{
    friend class Calculator;
    int a,b;
    public:
    void setData(int n1,int n2)
    {
        a=n1;
        b=n2;
    }
    void getData()
    {
        cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
};

int Calculator :: sumOfreal(Complex c1,Complex c2)
{
    return(c1.a + c2.a);
}
int Calculator :: sumOfcomp(Complex c1,Complex c2)
{
return(c1.b+c2.b);
}

int main()
{
  Complex c1,c2;
  c1.setData(3,4);
  c1.getData();

  c2.setData(4,5);
  c2.getData();

  Calculator realSum,complexSum;
  int g=realSum.sumOfreal(c1,c2);
  int h=complexSum.sumOfcomp(c1,c2);
  cout<<"The sum of the real parts of the two given complex numbers is "<<g<<endl;
  cout<<"The sum of the complex parts of the two given complex numbers is "<<h<<endl;
    return 0;
}