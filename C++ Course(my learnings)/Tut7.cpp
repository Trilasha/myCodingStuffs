#include <iostream>
using namespace std;

int c = 45;

int main()
{
    //**********************BUILD IN DATA TYPES***************************
    //int a, b, c;
    //cout << "Enter the value of a" << endl;
    //cin >> a;
    //cout << "Enter the value of b" << endl;
    //cin >> b;
    //c = a + b;
    //cout << "The sum is " << c << endl;
    //cout << "The global c is " << ::c << endl; //In order to print global variable,scope resolution operator(and newspace)(::)is used



    //**********************FLOAT,DOUBLE AND LONG DOUBLE LITERALS***************************

   // float d=34.4f;
   // long double e=34.4l;                                                //By default in c++,decimal points are marked as double so to make the floating,write f or F after the number...
   // cout<<"The value of d is "<<d<<endl<<"The value of e is "<<e<<endl; //Similarly,l or L can be written for long double
   // cout<<"The size of 34.4 is "<<sizeof(34.4)<<endl;
   // cout<<"The size of 34.4 is "<<sizeof(34.4f)<<endl;
   // cout<<"The size of 34.4 is "<<sizeof(34.4F)<<endl;
   // cout<<"The size of 34.4 is "<<sizeof(34.4l)<<endl;
   // cout<<"The size of 34.4 is "<<sizeof(34.4L)<<endl;
    




    //**********************REFERENCE VARIABLES***************************
    float x=455;
    float &y=x;
    cout<<x<<endl;
    cout<<y<<endl;


    //**********************TYPECASTING***************************
    float a=48.9;
    int b=68;
    cout<<"The value of a is "<<(int)a<<endl;   //both the formats are correct and acceptable
    cout<<"The value of a is "<<int(a)<<endl;

    cout<<"The value of a is "<<(float)b<<endl;
    cout<<"The value of a is "<<float(b)<<endl;

    int c=int(b);
    cout<<"The expression is "<<b+a<<endl;
    cout<<"The expression is "<<b+int(a)<<endl;
    cout<<"The expression is "<<b+(int)a<<endl;



    return 0;
}