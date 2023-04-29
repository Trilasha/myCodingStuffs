// C++ Function Templates and Function Templates with Parameters

// Till now we have been studying class templates
#include <iostream>
using namespace std;
float funcAverage(int a, int b)
{
    float avg = (a + b) / 2.0; // If 2 is written then answer will b3 3.000000 because int/int=int no matter what datatype we give
    return avg;                // In case of 2.0,we will get 3.500000 because int/float = float
}
float funcAverage2(int a, float b)
{
    float avg = (a + b) / 2.0; // If 2 is written then answer will b3 3.000000 because int/int=int no matter what datatype we give
    return avg;                // In case of 2.0,we will get 3.500000 because int/float = float
}
int main()
{
    float a;
    // a=funcAverage(5,2);
    a = funcAverage2(5, 2.4);

    // Hence to avoid making so many functions for different datatypes we use function templates
    //-->Move to the next Tutorial program
    //-->There will be demonstrated the other half of this tutorial...
    printf("The average of these numbers is %f", a);
    return 0;
}