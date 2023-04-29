//*******Destructors in C++*******
#include <iostream>
using namespace std;
//Destructors  never take an arument nor does it return any value
int count=0;//Made 'count' a global variable
class num
{
    public:
    num()
    {
        count++;
        cout<<"This is the time when constructor is called for object number"<<count<<endl;
    }
    ~num()
    {
        cout<<"This is the time when my destructor is called for object number "<<count<<endl;
        count--;
    }
};
int main()
{
  cout<<"We are inside our main function"<<endl;
  cout<<"Creating first object n1"<<endl;
  num n1;
  //Creating a block to define its scope
  {
cout<<"Entering this block"<<endl;
cout<<"Creating two more objects"<<endl;
num n2,n3;
cout<<"Exiting this block"<<endl;
  }
  cout<<"back to main"<<endl;

    return 0;
}