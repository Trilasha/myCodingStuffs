// Doing the previous code but now using function templates
#include <iostream>
using namespace std;
// template<class T1,class T2 >   //Example1
// float funcAverage(T1 a,T2 b)
//{
// float avg=(a+b)/2.0;
// return avg;
// }

template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <class T1, class T2>
float funcAverage(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;

    return avg;
}
int main()
{
    float a;
    a = funcAverage(5, 2.4);
    printf("The average of these numbers is %f\n", a);
    int x = 5, y = 7;
    swapp(x, y); // swap cannot be used because it is already present in the standard namespace
    cout << x << endl
         << y;
    return 0;
}