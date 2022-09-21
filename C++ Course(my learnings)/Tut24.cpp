//************STATIC DATA MEMBERS AND METHODS IN C++*********************
//------->A)STATIC DATA MEMBERS
//In this case count is a static data member of the class Employee

#include <iostream>
using namespace std;
class Employee
    {
        int id;
        //int count=0;//We will make this static by getting it out of the class
        static int count;//No need to initialize it because by default static variables are initialized from 0
        public:
        void setData(void)
        {
            cout<<"Enter the Id:"<<endl;
            cin>>id;
            count++;
        }
        void getData(void)
        {
            cout<<"The Id of the employee is "<<id<<" and this is employee number"<<count<<endl;
        }



        //------->B)To understand static functions
        //Static functions are created to get access to only the static variables present in the program
        static void getCount(void)
        {
            //cout<<id;//Will show an error because Id is not a static variable
            cout<<"The value of count is "<<count<<endl;
        }
    };
    //Steps for making count a static variable(also observe the difference when count is made static and when it is simply a variable)
    int Employee::count;//However if we want the starting value to be something else besides 0 then it can be written in this line
                        //like int Employee::count=1000;
int main()
{
    Employee harry,lavish,rohan;
    //harry.id=1;
    //harry.count=1;//cannot do this as id and count are private
    harry.setData();
    harry.getData();
    Employee :: getCount();

    lavish.setData();
    lavish.getData();
    Employee :: getCount();

    rohan.setData();
    rohan.getData();
    Employee :: getCount();


    return 0;


    //That's why static variables are called class variables 
    //Because it's not an object property but a class property
    //So the value of count for each new onject comes from the previous one
    //Only one copy of static variable is made and it is maintained throughout
    //Its transparency and scope is within the class and lifetime is till the program gets terminated
    //Static variable is only one and all the objects share it
}