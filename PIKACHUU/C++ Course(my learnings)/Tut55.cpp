//*******Pointers to Derived Classes*******
//RUN TIME POLYMORPHISM
#include <iostream>
using namespace std;
class BaseClass
{
public:
int var_base;
void display()
{
    cout<<"The value of the variable in the BaseClass "<<var_base<<endl;
}
};
class DerivedClass : public BaseClass
{
public:
int var_derived;
void display()
{
    cout<<"The value of the variable in the BaseClass "<<var_base<<endl;
    cout<<"The value of the variable in the DerivedClass "<<var_derived<<endl;

}
void d()
{
    cout<<"Good"<<endl;
}

};

int main()
{
    BaseClass *base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->var_base=34;
    //base_class_pointer->var_derived=135; //will show an error 
    base_class_pointer->display();
    base_class_pointer->var_base=3420;
    base_class_pointer->display();
    //base_class_pointer->d();//will show an error because base class has no member function called d

    DerivedClass *derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_derived=97;
    derived_class_pointer->display();

    derived_class_pointer->var_base=45;
    derived_class_pointer->display();








    return 0;
}