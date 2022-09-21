//*******Revisiting Pointers new and delete Keywords in C++*******
#include <iostream>
using namespace std;
int main()
{
    //****ALL DYNAMICALLY ALLOCATED****
    //Basic example
    int a=4;
    int* ptr=&a; 
    *ptr =999; //No need to give bracket for single entry but can also be given 
    cout<<"The value of a is "<<*(ptr)<<endl;

    //New operator
    //int *p=new int(40);
    float *p=new float(40.78);
    cout<<"The value at address p is "<<*(p)<<endl;

    //Creating an array(dynamically allocated block of memory)
    int *arr=new int[3];
    arr[0]=10;
    *(arr + 1)=20;   //arr[1]=20; //Both are correct
    arr[2]=30;
    delete[] arr;    //On writing this we get garbage values for arr[0] and arr[1]//Now the entire block of array is emptied to store new values
    cout<<"The value of arr[0] is "<<arr[0]<<endl;
    cout<<"The value of arr[1] is "<<arr[1]<<endl;
    cout<<"The value of arr[2] is "<<arr[2]<<endl;





    return 0;
}