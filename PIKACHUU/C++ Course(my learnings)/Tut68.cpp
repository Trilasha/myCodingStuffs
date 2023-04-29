// Member Function Templates in C++
#include <iostream>
using namespace std;
template <class T>
class Harry
{
public:
    T data;
    Harry(T a)
    {
        data = a;
    }
    // void display() //1st way of writing the function(INSIDE THE CLASS)
    //{
    //     cout<<data;
    // }

    void display(); // Second way of writing the function (OUTSIDE THE CLASS)
};

template <class T> // Second way of writing the function (OUTSIDE THE CLASS)
void Harry<T>::display()
{
    cout << data;
}

int main()
{
    Harry<int> h(5.7);
    Harry<float> h2(7);

    cout << h.data << endl;
    h.display();
    cout << endl;
    cout << h2.data << endl;
    h2.display();
    return 0;
}