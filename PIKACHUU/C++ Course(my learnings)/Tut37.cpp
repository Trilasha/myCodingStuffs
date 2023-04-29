//*******Inheritance Syntax and Visibility Mode in C++*******
#include <iostream>
using namespace std;

//Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(){};
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
};

//Derived Class Syntax
/*
    class {{derived-class-name}}: {{visibility-mode}}{{base-class-name}}
    {
        class members/methods/etc...
    }
    NOTE:
    -->Default visibility mode is private
    -->If visibility is private,then the public members of base class will become private members of derived class
    -->If the visibility is public,then the public members of base class will become the public members of the derived class
    -->Private members of the base class can never be inherited in the derived class
    */
//Creating a Programmer class derived from Employee Base class
class Programmer : public Employee
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    //or else we can write it as int languageCode =9;
    void getData()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);  //default constructor has to be created in order to write it as harry and rohan first
    cout << harry.salary << endl; //For this 'salary' must be made public
    cout << rohan.salary << endl;
    Programmer skillF(1); //a default constructor must be created in the base class otherwise calling the derived class will create a problem,but why?
    cout << skillF.languageCode << endl;

    cout << skillF.id << endl;
                      //will show an error because visibility is private
    skillF.getData(); //But the id can be displayed using a function

    return 0;
}
