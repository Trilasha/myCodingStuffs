#include <iostream>
using namespace std;
inline int product(int x, int y) //inline can be used when the function is called multiple times
{                                //DON'T USE INLINE WITH RECURSIONS,STATIC VARIABLES,LOOP,SWITCH
    return x * y;                //equest is sent to the compiler to make a function inline so all do not get the approval depending upon various reasons
}

float moneyReceived(int currentMoney, float factor = 1.04)//all the default arguments must be written to the extreme right and compulsory arguments to the extreme left
{
    return currentMoney * factor;
}

//CONSTANT ARGUMENTS>>> int strlen(const char*p);//mostly applicable for references,variables and pointers;especially arguments passed by reference


int main()
{
    int a, b;
    cout << "Enter the values of a and b : " << endl;
    cin >> a >> b;
    cout << "The product of a and b is " << product(a, b) << endl;

    int money = 100000;
    cout << "If you have " << money << " Rs in your bank account,you will receive " << moneyReceived(money) << " Rs after 1 year" << endl;
    //If along with money,the factor value is also written in the bracket then the new fed value will be considered 
    //and the default set value will be ignored in that case
    //But without any specific value,the set value is taken into account
    return 0;
}