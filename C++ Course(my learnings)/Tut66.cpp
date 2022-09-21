// C++ Templates : Class Templates with Default Parameters
#include <iostream>
using namespace std;
template <class T1 = int, class T2 = float, class T3 = char>
class Trilasha
{
public:
    T1 a;
    T2 b;
    T3 c;
    Trilasha(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        c = z;
    }
    void display()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
    }
};
int main()
{
    Trilasha<> t(4, 6.9, 'c'); // The angular brackets can be left empty so that the default parameters come into play
    t.display();

    cout << endl;

    // Now setting our own user defined parameters
    Trilasha<float, char, char> T(4.8, 'g', 'h'); // When data type is float,if we enter a character value then ASCII value is returned
    T.display();                                  // In case of char data type,if integer or floating point value is given then no output displayed or any random symbols appear

    return 0;
}