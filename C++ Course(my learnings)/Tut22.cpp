//************OOPS RECAP AND NESTLING OF MEMBER FUNCTIONS**************
/*
OOPS-Classes and Objects
C++ -->Initially called -->C with classes by stroustroup
classes-->extension of structures(in C)
structures had limitations
        -->members are public
        -->no methods
classes-->structures+more
classes-->can have methods and properties
classes-->can make few members as private and few as public
structures in C++ are typedefed
you can declare objects along with the class declaration
like;
          class Employee{
              //class definition
          } harry,rohan,lovish;
harry.salary=8 makes no sense if salary is private

*/





//Nesting of member functions
#include <iostream>
#include <string>//s.at and s.length are the functions of string library
using namespace std;
class binary
{
    //private:
    string s; //#########  by default in class everyhting is private unless mentioned;so even without writing private: it will run smoothly
    
public:
    void read(void);    //Declaration
     void chk_bin(void);//Declaration
    void ones(void);
    void display(void);
};


void binary ::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s; //string data type has been used so that the s.length function can be used
}
void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1') //remember the way of representing each element of the string
        {
            cout << "Incorrect binary format" << endl;
            exit(0);//It will terminate the program there and then
        } 
    }
}
void binary :: ones(void)
{
    //chk_bin();//nesting of functions
for (int i = 0; i < s.length(); i++)
{
    if (s.at(i)=='0')
    {
       s.at(i)='1';
    }
    else if (s.at(i)=='1')
    {
    s.at(i)='0';
    }
}
}
void binary :: display(void)
{
    cout<<"Displaying your binary number"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout<<s.at(i);
    }
    
}



int main()
{
    binary b;
    b.read();
   b.chk_bin();//To understand the nesting part,write this function inside the ones and then run the code
    b.display();//In case if the chk_bin is made private then it can no longer be called...
    cout<<endl;
    b.ones();
    b.display();
    return 0;
}