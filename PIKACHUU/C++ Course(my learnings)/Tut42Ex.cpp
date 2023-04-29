//*******Inheritance Exercise*******
//***I SOLVED IT MYSELF WITHOUT ANY HELP***
/*
Create 2 classes
1.Simple calculator:-takes input of 2 numbers using a utility function and performs +,-,*,/ and displays the results using another function.
2.Scientific calculator:-takes input of 2 numbers using a utility function and performs any four scientific operations of your choice and display the results using another function .

Create another class HybridCalculator and inherit it using these 2 classes:
Q1)What type of inheritance are you using?
Q2)Which mode of inheritance are you using?

ANSWERS
1)I have used multi level inheritance to make hybrid calculator
2)I am using public mode of visibility

*/
#include <iostream>
#include <cmath>
using namespace std;
class SimpleCalculator
{
    double a, b;

public:
    void set_data(double num1, double num2)
    {
        cout << "Enter the first value: " << endl;
        cin >> num1;
        cout << "Enter the second value: " << endl;
        cin >> num2;
        a = num1;
        b = num2;
    }
    double get_data1()
    {
        return a;
    }
    double get_data2()
    {
        return b;
    }

    void operation1()
    {
        int opt;
        cout << "Press: " << endl
             << "1.Addition" << endl
             << "2.Subtraction" << endl
             << "3.Multiplication" << endl
             << "4.Division" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "The sum of " << a << " and " << b << " is " << a + b << endl;
            break;
        case 2:
            cout << "The difference of " << a << " and " << b << " is " << a - b << endl;
            break;
        case 3:
            cout << "The product of " << a << " and " << b << " is " << a * b << endl;
            break;
        case 4:
            cout << "The quotient of " << a << " and " << b << " is " << a / b << endl;
            break;
        }
    }
};
class ScientificCalculator : public SimpleCalculator
{
    double rad;

public:
    void choose()
    {
        int cho;
        cout << "Out of the two entered numbers,which one do you want to use for the scientific calculation?" << endl
             << "Press: 1 for the first and 2 for the second" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            operation2();
            break;

        default:
            operation3();
            break;
        }
    }
    void operation2()
    {
        int che;
        cout << "Press:" << endl
             << "1.sin" << endl
             << "2.cos" << endl
             << "3.tan" << endl;
        cin >> che;
        rad = get_data1() * (3.14 / 180);
        switch (che)
        {
        case 1:
            cout << "The sine of the angle(assumed to be in degrees) is " << sin(rad) << endl;
            break;
        case 2:
            cout << "The cosine of the angle(assumed to be in degrees) is " << cos(rad) << endl;
            break;
        case 3:
            cout << "The tangent of the angle(assumed to be in degrees) is " << tan(rad) << endl;
            break;
        }
    }
    void operation3()
    {
        int che;
        cout << "Press:" << endl
             << "1.sin" << endl
             << "2.cos" << endl
             << "3.tan" << endl;
        cin >> che;
        rad = get_data2() * (3.14 / 180);
        switch (che)
        {
        case 1:
            cout << "The sine of the angle(assumed to be in degrees) is " << sin(rad) << endl;
            break;
        case 2:
            cout << "The cosine of the angle(assumed to be in degrees) is " << cos(rad) << endl;
            break;
        case 3:
            cout << "The tangent of the angle(assumed to be in degrees) is " << tan(rad) << endl;
            break;
        }
    }
    int get_rad()
    {
        return rad;
    }
};
class HybridCalculator : public ScientificCalculator
{
public:
    void option()
    {
        int opt2;
        double f, s;
        cout << "Press:"
             << "1.To perform simple calculation" << endl
             << "2.To perform scientific calculation" << endl;
        cin >> opt2;
        switch (opt2)
        {
        case 1:
            set_data(f, s);
            operation1();

            break;
        case 2:
            set_data(f, s);
            choose();
        }
    }
};

int main()
{
    double d, g;
    HybridCalculator h1;
    // s1.set_data(d,g);
    //s1.operation1();
    //s1.choose();
    h1.option();
    return 0;
}