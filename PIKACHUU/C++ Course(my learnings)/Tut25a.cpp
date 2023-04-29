//*****************ARRAY OF OBJECTS AND PASSING OBJECTS AS FUNCTIONS ARGUMENTS IN C++*****************
#include <iostream>
using namespace std;
class Employee
    {
        int Id;
        int salary;
        public:
        void setId(void)
        {
            salary=122;
            cout<<"Enter the id of the employee"<<endl;
            cin>>Id;
        }
        void getId(void)
        {
            cout<<"The Id of this employee is "<<Id<<endl;
        }
    };



int main()
{
    /*Employee harry,rohan,lovish,shubhan;
    harry.setId();
    harry.getId();
    */
   //Now the above thing is done using arrays
   Employee fb[4];
   for (int i = 0; i < 4; i++)
   {
       fb[i].setId();
       fb[i].getId();
   }
   
    return 0;
}