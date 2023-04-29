#include <iostream>
using namespace std;
int main()
{
    int a=4;
    int*b = &a;//Pointer to variable
int**c = &b;//Pointer to pointer
cout<<"The value at the variable a is: "<<a<<endl;
cout<<"The value at address b is: "<<*b<<endl;
cout<<"TThe value at address value_at(value_at(c)): "<<**c<<endl;



cout<<"The address of a is: "<<&a<<endl;
cout<<"The address of a is: "<<b<<endl;



cout<<"The address of b is: "<<&b<<endl;
cout<<"The address of b is: "<<c<<endl;


    return 0;
}