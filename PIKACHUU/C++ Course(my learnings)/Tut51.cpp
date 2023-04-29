//*******Pointers to Objects and Arrow Operator in C++*******
#include <iostream>
using namespace std;
class Complex
{
    int real, imaginary;

public:
    void get_data()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }
    void set_data(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};
int main()
{
    Complex c1;                                        //-->Way1
    //c1.set_data(1, 54);
    //c1.get_data();

    //Complex *ptr=&c1;                                //-->Way2 using the first line of way1
    //(*ptr).set_data(1,54); //bracket must because . has higher precedence over *
    //(*ptr).get_data();

    Complex *ptr=new Complex;                          //-->Way3
    //(*ptr).set_data(1,54); //this line can also be written using an arrow
    ptr->set_data(1,54);                               //-->Another way of writing the above line
    //(*ptr).get_data(); //similarly
    ptr->get_data();

    

    //Array Of Objects //To be explained in the next video...
    Complex *ptr1=new Complex[4];
    ptr1->set_data(1,4);
    ptr1->get_data();

    return 0;
}