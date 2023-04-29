/*In C++ sequence of bytes corresponding to I/O are commonly known as streams
INPUT STREA>>>Direction of flow of bytes takes place from input device
OUTPUT STREAM>>>.......from main memory to the output device(Eg-Display)
Lists of reserved keywords and data type/range are also given by harry bhai*/
#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    // << is called the insertion operator
    // >> is called the extraction operator
    cout << "Enter the value of num1\n";
    cin >> num1;
    cout << "Enter the value of num2\n";
    cin >> num2;
    cout << "The sum is: " << num1 + num2;
    return 0;
}
