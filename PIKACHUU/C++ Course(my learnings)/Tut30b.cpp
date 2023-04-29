#include <iostream>
using namespace std;
 class Point
    {
int x,y;
public:
Point(int a,int b)
{
x=a;
y=b;
}
void displaypoint()
{
    cout<<"The point is ("<<x<<","<<y<<")"<<endl;
}
};

int main()
{
  Point p(3,6);
  p.displaypoint();

  Point q(8,9);
  q.displaypoint();
    return 0;
}