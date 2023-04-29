#include <bits/stdc++.h>
using namespace std;
/*
A function fun is called direct recursive if it calls the same function fun. A function fun is called indirect recursive if it calls another function say fun_new and fun_new calls fun directly or indirectly. Difference between direct and indirect recursion has been illustrated in Table 1. 

// An example of direct recursion
void directRecFun()
{
    // Some code....

    directRecFun();
// Some code...
}

// An example of indirect recursion
void indirectRecFun1()
{
    // Some code...

    indirectRecFun2();

    // Some code...
}
void indirectRecFun2()
{
    // Some code...
    indirectRecFun1();
// Some code...
}
*/


//Direct recursion example can be the fibonacci series
//The example shown by seniors for indirect recursion is demonstrated below
void printeven(int,int);//If printeven is written above printodd,then printodd prototype should be given
void printodd(int,int);                        //Hence better to declare both whenever written
void printodd(int a,int n)
{
    if(a>n)
    return;
    else
    {
        cout<<a<<" ";
        printeven(a+1,n);
        return;
    }
}
void printeven(int a,int n)
{
    a++;
    printodd(a,n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    printodd(1,n);


    return 0;
}