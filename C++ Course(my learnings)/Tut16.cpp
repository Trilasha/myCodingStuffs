#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int c = a + b;
    return c;
}

//void function to swap the values using pointer references
void swapPointer(int *a, int *b)
{                  //temp a b
    int temp = *a; // 4   4 5
    *a = *b;       // 4   5 5
    *b = temp;     // 4   5 4
}

//void function to swap the values using C++ references
void swapReference(int &a, int &b) //Here a and b are pointers pointing to the actual parameters/arguments
{                  
    int temp = a; 
    a = b;       
    b = temp; 
   
}

int main()
{
    int a = 4, b = 5;
    cout << "The sum of the given two numbers is " << sum(a, b) << endl;

    cout << "The value of a is " << a << " and the value of b is " << b << endl;
    swapPointer(&a, &b); //THIS WILL SWAP a AND b USING POINTER REFERENCE        //If this is done by call by value then the output will not be accurate
                                                                                   //So to actually swap the values,call by reference is what we have to do
    cout << "The value of a is " << a << " and the value of b is " << b << endl;
 swapReference(a,b); //THIS WILL SWAP THE VALUES AGAIN USING C++ REFERENCE VARIABLES
    cout << "The value of a is " << a << " and the value of b is " << b << endl;

        
    //**************swapReference(a,b)=765; 
    //*********cout << "The value of a is " << a << " and the value of b is " << b << endl;
    //*****The above two line code will change the value of a if
    //***int & swapReference...return a;(other things same as void one)
    //because a is a reference variable which points to a of the main function
    //hence 765 will become the new value of a 


    

    return 0;
}