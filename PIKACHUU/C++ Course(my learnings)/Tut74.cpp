// Function Objects(also called as Functors) in C++ STL
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
int main()
{
    // Function Objects: Function wrapped in a class so that it is available like an object
    int arr[] = {1, 3, 4, 12, 54, 7}; // by default in ascending  //in this case sort is a functor
    sort(arr, arr + 5);               // for this portion we are using the algorith library //greater<int>() is another function object used for arranging in descending order
                                      // sort(arr,arr+5,greater<int>())

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl; // It will sort only the first 5 elements as per our instruction and the remaining elements will remain as it is
    }

    return 0;
}