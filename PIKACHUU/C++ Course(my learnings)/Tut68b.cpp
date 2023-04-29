//Overloading template Functions
#include <iostream>
using namespace std;
 void func(int a)
    {
        cout<<"I am first func() "<<a<<endl;
        
    }

    template <class T>
    void func(T a)
    {
        cout<<"I am templatised func() "<<a<<endl;

    }

    template <class T>
    void funcTWO(T a)
    {
        cout<<"I am templatised func() "<<a<<endl;

    }
int main()
{
   func(4);//Exact match takes the highest priority
   funcTWO(8);//It will display the template one because no exact match is available
    return 0;
}