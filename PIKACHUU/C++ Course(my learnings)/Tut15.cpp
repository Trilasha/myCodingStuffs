#include <iostream>
using namespace std;
//int sum(int a,int b);//RIGHT  //this is function prototyping if function is defines after main then declaring it here will give accurate results
//int sum(int a,b);    //WRONG
//int sum(int,int);    //RIGHT
//void greeting(void); //RIGHT
void greeting();       //RIGHT   


int sum(int a,int b)
{
    int c=a+b;
    return c;
}
int main()
{
    int num1,num2;
    cout<<"Enter the first number: "<<endl;
    cin>>num1;
    cout<<"Enter the second number: "<<endl;
    cin>>num2;
    cout<<"The sum of thye entered numbers is "<<sum(num1,num2)<<endl;
    greeting();

    return 0;
}

void greeting()
{
    cout<<"Helo World...Heartfelt greetings"<<endl;

}
//So in this program,sum function has been defined and declared at one place
//whereas in the void function,declaration and definition has been separately
//void function can be used to avoid writing the cout statements multiple times...

