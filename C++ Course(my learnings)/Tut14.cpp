//********STRUCTURES,UNIONS AND ENUM**************


#include <iostream>
using namespace std;

typedef struct employee
{
    int eId;
    char favChar;
    float salary;
} ep;

typedef union currency
{
    int rice;
    char car;
    float pounds;

} un;


int main()
{
    enum Meal{breakfast,lunch,dinner};    //Now enum Meal has become a data type
    cout<<breakfast;
    cout<<lunch;
    cout<<dinner<<endl;

    Meal a=breakfast;    //Another way of using it in C++
    cout<<a<<endl;
    Meal b=lunch;
    cout<<b<<endl;
    Meal c=dinner;
    cout<<c<<endl;

    cout<<(c==2)<<endl;    //ANother way where condition is applied and checked //If a==0 is true then it will return 1 or else 0



    //FOR STRUCTURE SPECIFICALLY
ep harry;
harry.eId=1;
harry.favChar='t';
harry.salary=12,00,00,000;
cout<<"The employee Id of Mr.Harry is : "<<harry.eId<<endl;
cout<<"The favourite character of Mr.Harry is : "<<harry.favChar<<endl;
cout<<"The salary of Mr.Harry is : "<<harry.salary<<endl;


//FOR UNION SPECIFICALLY
un m1;
m1.rice=34;
m1.car = 'c';
cout<<m1.rice<<endl;//this will return a garbage value if any other member is assigned a value(in this case m1.car)
cout<<m1.car<<endl; //But now this line will show correct value and the above one still garbage
                    //If lineno.33 is not written then also the car value will be returned correctly

return 0;
}