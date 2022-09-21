//************Constructors With Default Arguments in C++***************
#include <iostream>
using namespace std;
 class Simple
    {
        int data1, data2, data3;

    public:
        Simple(int a, int b = 7, int c = 9)
        {
            data1 = a;
            data2 = b;
            data3 = c;
        }
        void printData(); //Only the declaration
    };
    void Simple :: printData()
    {
        cout << "The value of dat1,data2 and data3 are " << data1 << "," << data2 << " and " << data3 << endl;
    }
int main()
{
   Simple s1(12,14,18);
   s1.printData();
   Simple s2(14,18);//Unless specific value is given it will take the default value like data3 in this case
   s2.printData();
Simple s3(12);
   s3.printData();
  // Simple s4;
  //s4.printData(); //this will show an error because no such specific constructor has been created
    return 0;
}