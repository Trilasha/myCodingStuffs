//*******Ambiguity Resolution in Inheritance*******
#include <iostream>
using namespace std;
class base1
{
public:
    void greet()
    {
        cout << "How are you?" << endl;
    }
};
class base2
{
public:
    void greet()
    {
        cout << "Kya hal chal?" << endl;
    }
};
class derived : public base1, public base2
{
    int a;

public: //Follow the steps given below in order to remove the ambiguity thus created
    void greet()
    {
        base1::greet();
    }
};
//No need to comment out the above made classes because unless objects are created classes wil remain disfunctional...

class B
{
public:
    void say()
    {
        cout << "Hello World" << endl;
    }
};
class D : public B
{
    int a;

public:
    void say()
    {
        cout << "Hello cute people" << endl;
    }
};

int main()
{
    //$$$ AMBIGUITY 1 $$$

    //base1 base1obj;
    //base2 base2obj;
    //base1obj.greet();
    //base2obj.greet();
    //derived d;
    //d.greet(); //only writing this will create an ambiguity so need to mention spcifically

    //$$$ AMBIGUITY 2 $$$

    B b;
    b.say();
    D d;
    d.say();  //Ambiguity resolved automatically as first preference given to the function of its own class and if not available then the base class one.
    return 0; //or else D's new say function will overwrite the say function of the B class
}