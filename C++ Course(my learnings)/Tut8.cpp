#include <iostream> //endl is a manipulator
#include <iomanip>
using namespace std;
int main()
{
    //int a=34;
    //cout<<"The value of a is "<<a<<endl;
    //a=45;
    //cout<<"The value of a is "<<a<<endl;
    //const int a = 34;
    //cout << "The value of a is " << a << endl;
    //Now trying to give new value to a will throw an error because we have written const before int
    

    //**********MANIPULATORS IN C++*******************
    //endl is alos a manipulator
    //After writing iomanip; we can use setw
    //int c = 3, d = 78, e = 1233;
    //cout << "The value of a is: " << c << endl; //setw is present in iomanip header file
    //cout << "The value of a is: " << d << endl;
    //cout << "The value of a is: " << e << endl;
    //cout << "The value of a is: " << setw(4) << c << endl;//It will occupy 4 character space in the output
    //cout << "The value of a is: " << setw(4) << d << endl;
    //cout << "The value of a is: " << setw(4) << e << endl;


    //****************OPERATORS PRECEDENCE******************
    int a=3,b=4;
    int c=((((a*5)+b)-45)+87); //brackets are only for our ease,without brackets also the compiler will give accurate result on the basis of the order of the preferences
    //en.cppreference.com for the tabe of operators precedence
    //* above +/-,then + followed by - in the immediate next row
    //order top or below
    //If in the same row then left to right associativity
    //brackets can be put accordingly then
    

    cout<<c;

    return 0;
}