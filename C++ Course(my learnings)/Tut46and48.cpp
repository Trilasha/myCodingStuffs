//********Constructors in derived Class*******
//EXAMPLE
/*
Case1:
class B:public A
{
//Order of execution of constructor -->first A() then B()
};
Case2:
class A:public B,public C
{
    //Order of execution of constructor -->B() then C() and A()
};
Case3:
class A:public B,virtual public C
{
    //Order of execution of constructor -->C() then B() and A()
};
*/
#include <iostream>
using namespace std;

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }
    void print_data_base1(void)
    {

        cout << "The value of data1 is " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }
    void print_data_base2(void)
    {

        cout << "The value of data2 is " << data2 << endl;
    }
};
class derived : public Base1, public Base2 //Changing the order here WILL DEFINITELY make a difference
{
    int derived1, derived2;

public:
    derived(int a, int b, int c, int d) : Base1(a), Base2(b) //Changing the order here will NOT make any difference
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printData(void)
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};
int main()
{
    derived trilasha(1, 2, 3, 4);
    trilasha.print_data_base1();
    trilasha.print_data_base2();
    trilasha.printData();

    return 0;
}