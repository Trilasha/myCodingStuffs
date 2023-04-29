//Undestanding function overloading



#include <iostream>
using namespace std;
int sum(int a, int b)
{
    return a+b;
}
int sum(float a,int b,int c) //In this case even though we are giving int type(say 3) but written float in formal parameters then also no issue as it will return int value finally
{                           
    return a+b+c;            //Compiler will try to match as much as possible the thing mentioned above this but in extreme cases it will return errors

}



//Another example to show overloaded functions
int volume(double r,int h)
{
    return(3.14*r*r*h); //better to give brackets
}
int volume(int x,int y,int z)
{
    return (x*y*z);
}
int volume(int s)
{
    return (s*s*s);
}

int main()
{
    cout<<"The sum of 3 and 6 is "<<sum(3,6)<<endl;
    cout<<"The sum of 3,6 and 9 is "<<sum(3,6,9)<<endl; //Even though two functions are named same but it will choose the desired one depending upon the arguments
    cout<<"The volume of the cube with side 6 is "<<volume(6)<<endl;
    cout<<"The volume of the cuboid with length,breadth and height as 3,4 and 5 respectively is "<<volume(3,4,5)<<endl;
    cout<<"The volume of the cylinder with radius 3.54 and height 9 is "<<volume(3.54,9)<<endl;


    return 0;
}