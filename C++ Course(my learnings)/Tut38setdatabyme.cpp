//*******Single Inheritance Deep Drive(In PUBLIC Mode)*******
#include <iostream>
using namespace std;
class base
{
    int data1;//private by default and is not inheritable
    public:
    int data2;
    int setData(int a,int b);//These are member functions
    int getData1();
    int getData2();
};
int base :: setData(int a=10,int b=20)
{
    data1=a;
    data2=b;
}
int base :: getData1()
{
    //cout<<"The value of data1 is "<<data1<<endl;
    return data1;
}
int base :: getData2()
{
    //cout<<"The value of data2 is "<<data2<<endl;
    return data2;
}


class Derived : public base//Class is being derived publically
{
int data3;
public:
int process(base);
int display(base);
};
int Derived :: process(base c1)
{
    data3=c1.getData2()*c1.getData1();
}
int Derived:: display(base c1)
{
    cout<<"Value of data 1 is "<<c1.getData1()<<endl;
    cout<<"Value of data 2 is "<<c1.getData2()<<endl;
    cout<<"Value of data 3 is "<<data3<<endl;
}
int main()
{
    base c1;
    c1.setData(30,40);
    c1.getData1();
    c1.getData2();
   Derived der;
   der.setData();//Though setData is a function of the base class but since it is public so it is also available in the derived class 
   der.process(c1);
   der.display(c1);
   //Thing to be noted is the difference in accesing data1 and data2 in the derived class function'process'

   //QUESTION-->can we set data1?
   //Some alternations are created by me to set the data1 and use that in the derived class
   return 0;
}