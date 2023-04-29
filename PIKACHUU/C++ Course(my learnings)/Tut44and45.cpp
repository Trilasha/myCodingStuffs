//*******Virtual base Class in C++*******
#include <iostream>
using namespace std;
/*                      class A-->Virtual Base Class
           class B                                        class C
                        class D
//Syntax
class B : virtual public A
{

};
class C : virtual public A
{

};
*/

//An Example showing the application of 
/*
student-->test
student-->sports
test   -->result
sports -->result
*/
class student
{
protected:
    int roll_no;

public:
    void set_number(int a)
    {
        roll_no = a;
    }
    void print_number(void)
    {
        cout << "Your roll no is " << roll_no << endl;
    }
};
class test : virtual public student //or public virtual can also be written
{
protected:
    float math, physics;

public:
    void set_marks(float m1, float m2)
    {
        math = m1;
        physics = m2;
    }
    void print_marks(void)
    {
        cout << "Your result is here: " << endl
             << "Math:" << math << endl
             << "Physics:" << physics << endl;
    }
};
class sports : public virtual student
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }
    void print_score(void)
    {
        cout << "Your PT score is:" << score << endl;
    }
};
class result : public test, public sports
{
private:
    float total;

public:
    void display()
    {
        total = math + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Your total score is : " << total << endl;
    }
};
int main()
{
    result r1;
    r1.set_number(4219);
    r1.set_marks(99, 99);
    r1.set_score(95);
    r1.display();
    return 0;
 //Without the word virtual the compiler will show an error   






}