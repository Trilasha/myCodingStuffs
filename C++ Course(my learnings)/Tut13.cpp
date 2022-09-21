#include <iostream>
using namespace std;
int main()
{
    int marks[4]={12,14,16,18};

    //for (int i = 0; i < 4; i++)
    //{
    //    cout<<"The value present at the "<<i<<" element of the marks' array is "<<marks[i]<<endl;
    //}

    //int i=0;
    //while (i!=4)
    //{
    //    cout<<"The value present at the "<<i<<" element of the marks' array is "<<marks[i]<<endl;
    //    i++;
    //}
    
    //int i=0;
    //do
    //{ 
    //    cout<<"The value present at the "<<i<<" element of the marks' array is "<<marks[i]<<endl;
    //   i++;
    //} while (i!=4);

 //here simply writing marks will give the address of the first element of the array;no need to write any & unlike variables   


 //*********POINTER ARITHMETIC FORMULA***********
 //ADDRESS(new)=ADDRESS(current) + i*sizeof(data type);
 //i.e,(p+i)=p + i*sizeof(int)
 //where p =marks;(pointer p stores the address of marks[0])
 //data type = int

 //Also before cout any change in the value of any specific element will be reflected

 int* p=marks;
 cout<<*(p++)<<endl;
 cout<<*p<<endl;//So first it printed marks[0] and then incremented the value by one sizeof(int) and so the address of marks[0]
                 //has now taken the value of the address of marks[1] which on deferencing will give the value marks[1]
    return 0;
}