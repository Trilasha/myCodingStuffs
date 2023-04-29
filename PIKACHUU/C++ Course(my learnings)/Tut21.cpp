//*********CLASSES,PUBLIC AND PRIVATE ACCESS MODIFIERS************
//in C++,no need to write the keywoed typedef then how?
//For security purpose and also for entering functions,classes are preferred over structures
#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;
public:
    int d, e;
    void setData(int a1, int b1, int c1); //Declaration
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b<< endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
  }
};

void Employee :: setData(int a1, int b1, int c1)
{
    a=a1;
    b=b1;
    c=c1; //Correct way of writing

    //a1=a;
    //b1=b;
    //c1=c;//Wrong way of writing
}

int main()
{
Employee harry;
harry.d=9;
harry.e=19;
harry.setData(12,27,45);
//harry.a=12; //a,b,c cannot be declared in this way because they are private and can be accessed only through the function mentioned
harry.getData();

    return 0;
}