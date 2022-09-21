//*******Protected Access Modifier*******
#include <iostream>
using namespace std;
class Base
{
    protected://Just like private but it can be inherited like the public ones(but cannot be made public directly so is kept as protected) 
    int a;
    private:
    int b;
};
/*
For a protected member:
                         Public derivation         Private derivation            Protected derivation
 1.Private members       NOT INHERITED               NOT INHERITED                  NOT INHERITED
 2.Protected members     PROTECTED                    PRIVATE                       PROTECTED 
 3.Public members         PUBLIC                      PRIVATE                       PROTECTED

*/
class Derived:protected Base
{
    
};

int main()
{
Base b;
Derived d;
//cout<<b.a;//a has been inherited but since it is protected so cannot be displayed like that,same for cout<<d.a;(Hence code will not work in this case)
//in this case a is protected for both the base and the derived class
    return 0;
}