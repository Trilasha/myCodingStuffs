//*******This Pointer in C++*******
#include <iostream>
using namespace std;
class A
{
int a;
public:


//1.0-->
//void set_data(int a)
//{
////a=a;         //Doing this simply will not directly show any error but will display the output with a garbage value because local variables will get more preference 
//this->a=a;     //So this pointer is used now    
//}




//2.0-->
A & set_data(int a)   //reference variable
{
    this->a=a;
    return *this;

}
void get_data()
{
    cout<<"The value of a is "<<a<<endl;
}
};
int main()
{
    //This is a keyword which is a pointer which points to the object that invokes the member function

    A a;    //any name can be given to the object created not necessarily the same name as the class variable one
    //1.0-->
    a.set_data(4);
    a.get_data();

    //2.0-->
    a.set_data(4).get_data();
    return 0;
}