//*******File I/O in C++:-Reading and Writing Files*******
#include <iostream>
#include<fstream>
using namespace std;
/*
The 3 useful classes for working with files in C++ are:-
1)fstreambase
2)ifstream-->derived from fstreambase
2)ofstream-->derived from fstreambase

//In order to work with files in C++,you will have to open it.Primarily there are 2 ways to open a file:
//1)Using the constructor 
//2)Using the member function open() of the class
*/
int main()
{
    string st="Harry Bhai";
    string st2;
    //Opening files using constructor and writing it
    ofstream out("sample60.txt");    //Write operation            //Code not working
    out<<st;

    //Opening files using constructor and reading it
    ifstream in("sample60b.txt");      //Read operation
    //in>>st2;         //will continue to display the string until it encounters a blank space or a new line
    //To avoid this getline can be used as shown below
    getline(in,st2);//All teh things present in a single line will get displayed
    getline(in,st2);
    getline(in,st2);
    cout<<st2;
    return 0;
}