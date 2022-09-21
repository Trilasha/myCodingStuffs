//*******Multi level inheritance deep drive with code example*******
#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};
void Student ::set_roll_number(int r)
{
    roll_number = r;
}
void Student ::get_roll_number()
{
    cout << "The roll number is " << roll_number << endl;
}

class exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};
void exam::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}
void exam::get_marks()
{
    cout << "The marks obtained in mathematics is " << maths << endl;
    cout << "The marks obtained in physics is " << physics << endl;
}
class result : public exam
{
    float percentage;

public:
    void display()
    {
        get_roll_number();
        get_marks();
        cout << "Your percentage is " << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    /*
    NOTES:----
    -->If we are inhertitng B from A and C from B:[A-->B-->C]
    -->A is the base class for B and B is the base class for C
    -->ABC is called Inheritance Path
    */
    result trilasha;
    trilasha.set_roll_number(421);
    trilasha.set_marks(99, 98);
    trilasha.display();

    return 0;
}