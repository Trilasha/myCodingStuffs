#include <iostream>
using namespace std;
//***Syntax for the forloop
//for(initializaion,condition,updation)
//{
//    loop body(C++ code);
//}

//******Example of infinite loop
//for (i = 0; 34 < 40; i++)
//{
//    cout<<i<<endl;
//
//}

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        cout << i << endl;
    }
    //***********Then example of finite while loop is given
    //int i=10;
    //while (i<=40)
    //{
    //  cout<<i<<endl;
    //i++;
    //}

    //*******Example of infinite while loop
    //int i=1;
    //while (true)
    //{
    //  cout<<i<<endl;
    //i++;
    //}

    //#############    BEWARE OF INFINITE LOOP AS IT CAN EVEN DAMAGE YOUR MEMORY AND COMPUTER MIGHT GET HEATED #############

//*************EXAMPLE OF DO WHILE LOOP*******************
/*&int i=1;
do
{
    cout<<i<<endl;
    i++;
} while (i<40); //In this case instead of i<40 if we write  false then the output will be only 1 as the loop will run only once and then terminate
                //That is do-while starts checking the condition from the second time 

Diferrence betweendo-while loop and while loop is that even if the condition is false, do-while loop will run one time and stop 
whereas while loop will not run at all.
*/



    return 0;
}
