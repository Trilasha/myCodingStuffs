//*******Virtual functons in C++*******
#include <iostream>
using namespace std;
class BaseClass
{
public:
    int var_base = 1;
    virtual void display() //using virtual functions thus similar named functions in base and derived will henceforth get executed only from the derived one
    {
        cout << "1)The value of the variable in the BaseClass " << var_base << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived = 2;
    void display()
    {
        cout << "2)The value of the variable in the BaseClass " << var_base << endl;
        cout << "2)The value of the variable in the DerivedClass " << var_derived << endl;
    }
};
int main()
{
    BaseClass *base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    return 0;
    //run time polymorphism does not mean that the decision is taken at the time of compiling,
    //it simply means that the binding of the function address to an object occurs at the time of compiling 
    //
}