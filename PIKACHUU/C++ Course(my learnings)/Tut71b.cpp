// vector creating ways
#include <iostream>
#include <vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    cout << "Displaying this vector" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Ways to create a vector
    vector<int> vec1;        // zero length integer vector
    vector<char> vec2(4);    // 4-element character length vector
    vector<char> vec3(vec2); // 4-element character vector from vec2
    vector<int> vec4(6, 3);  // 6-element vector of 3s
    display(vec1);

    vec2.push_back('5');
    display(vec2);

    display(vec3);

    display(vec4);
    cout << "The size of the vector 4 is " << vec4.size();
    return 0;
}