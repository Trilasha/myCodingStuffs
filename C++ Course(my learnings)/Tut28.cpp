//Simplest example for friend function and to know the importance of forward declaration
#include<iostream>
using namespace std;
class Y;
class X
{
    friend void add(X, Y);
    int data;
public:
    void setvalue1(int value1)
    {
        data = value1;
    }
    };


class Y
    {
        friend void add(X, Y);
        int num;

    public:
        void setvalue2(int value2)
        {
            num = value2;
        }
    };




    void add(X o1, Y o2)
    {
        cout << "The sum of the two numbers is " << o1.data + o2.num << endl;
    }
    int main()
    {
        X o1;
        o1.setvalue1(3);
        Y o2;
        o2.setvalue2(6);
        add(o1, o2);
        return 0;
    }