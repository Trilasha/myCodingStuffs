#include <iostream>
using namespace std;
int main()
{
    //for (int i = 0; i < 4; i++)
    //{
    //    if (i == 2)
    //    {
    //        break; //Stops the iteration completely and exits the loop
    //    }
    //    cout << i << endl;
    //}


for (int i = 0; i < 40; i++)
    {
    // cout << i << endl; //cout cannot be written before continue but in case of break,anywhere it can be written within the loop
        if (i == 2)
        {
            continue;//Stops the current iteration and moves to the next iteration but does not exit the loop
        }
        cout << i << endl;
    }

    return 0;
}