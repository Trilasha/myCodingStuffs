#include<bits/stdc++.h>
using namespace std;  
class A  
{  
    protected:  
     int a;  
    public:  
    void get_a()  
    {  
        cout<<"Mein A hun"<<endl;
    }  
};  
  
class B  
{  
    protected:  
    int b;  
    public:  
    void get_a()  
    {  
        cout<<"Mein B hun"<<endl;
    }  
};  
class C : public A 
{  
   public:  
    void get_a()  
    {  
        cout<<"Mein C hun"<<endl;
    } 
};  
int main()  
{  
   C c;  
   c.get_a();  
  
    return 0;  
}