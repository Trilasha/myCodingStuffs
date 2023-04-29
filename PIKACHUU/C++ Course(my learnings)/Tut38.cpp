//*******Single Inheritance Deep Drive(In PUBLIC Mode)*******
#include<iostream>
using namespace std;
class base
{
    int data1;//private by default and is not inheritable
    public:
    int data2;
    void setData();//These are member functions
    int getData1();
    int getData2();
};
void base :: setData(void)
{
    data1=10;
    data2=20;
}
int base :: getData1()
{
    return data1;
}
int base :: getData2()
{
    return data2;
}


class Derived : public base//Class is being derived publically
{
int data3;
public:
void process();
void display();
};
void Derived :: process()
{
    data3=data2*getData1();
}
void Derived:: display()
{
    cout<<"Value of data 1 is "<<getData1()<<endl;
    cout<<"Value of data 2 is "<<data2<<endl;
    cout<<"Value of data 3 is "<<data3<<endl;
}
int main()
{
   Derived der;
   der.setData();//Though setData is a function of the base class but since it is public so it is also available in the derived class 
   der.process();
   der.display();
   //Thing to be noted is the difference in accesing data1 and data2 in the derived class function'process'

   //QUESTION-->can we set data1?
   return 0;
}