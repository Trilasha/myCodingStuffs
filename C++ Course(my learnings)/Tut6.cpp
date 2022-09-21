
//There are two types of header files:
//1.System Header files:It comes with the compiler
#include <iostream>
//2.User defined header files: It is written by the programmer
#include "this.h" //This file must be created before(.h file should be there in the current directory)

//C++ standard library headers(google out to know more on these libraries,en.cppreference.com)

using namespace std;
int main()
{
    int a = 4, b = 5;
    cout << "Operators in C++:" << endl; //(\n or endl same functionality)
    cout << "Following are the types of operators in C++" << endl;
    //Arithmetic Operators
    cout << "The value of a + b is" << a + b << endl;
    cout << "The value of a - b is" << a - b << endl;
    cout << "The value of a * b is" << a * b << endl;
    cout << "The value of a % b is" << a % b << endl;
    cout << "The value of a / b is" << a / b << endl;
    cout << "The value of a++ is" << a++ << endl;//First print then increment 
    cout << "The value of a-- is" << a-- << endl;//First print then decrement
    cout << "The value of ++a is" << ++a << endl;//First increment then print
    cout << "The value of --a  is" << --a << endl;//First decrement then print
    cout<<endl;


    //Assignment operators-->use to assign values to variables
    //int a=3,b=9;
    //char d='d';

    //Comparison Operators
    cout<<"Following are the types of conditional operators in C++:-"<<endl;
    cout<<"The value of a==b is"<<(a==b)<< endl;
    cout<<"The value of a!=b is"<<(a!=b)<< endl;
    cout<<"The value of a>b is"<<(a>b)<< endl;
    cout<<"The value of a<b is"<<(a<b)<< endl;
    cout<<"The value of a<=b is"<<(a<=b)<< endl;
    cout<<"The value of a>=b is"<<(a>=b)<< endl;
    cout<<endl;


    //Logical operators
    cout<<"Following are the types of logical operators in C++:-"<<endl;
    cout<<"The value of logical AND operator is :- (a==b)&&(a<b) is "<<((a==b)&&(a<b))<<endl;
    cout<<"The value of logical OR operator is :- (a==b)||(a<b) is "<<((a==b)||(a<b))<<endl;
    cout<<"The value of logical NOT operator is :(!(a==b)) is "<<(!(a==b))<<endl;

    


    

        return 0;
}
