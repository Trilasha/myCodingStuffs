//DONE BY MYSELF...
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
    friend int distance(Point,Point);
    int x,y;
    public:
    Point(int a,int b)
    {
        x=a;
        y=b;
    }
    void displaypoint()
    {
        cout<<"The entered point is ("<<x<<","<<y<<")"<<endl;
    }
};

int distance(Point p1,Point p2)
{
    int d;
    d=((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y));
    return sqrt(d);
}

int main()
{
    Point p1(1,0);
    p1.displaypoint();

    Point p2(9,6);
    p2.displaypoint();

int dis=distance(p1,p2);
cout<<"The distance between the two given points is: "<<dis<<endl;

    return 0;
}