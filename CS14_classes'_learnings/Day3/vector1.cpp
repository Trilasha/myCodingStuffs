#include <bits/stdc++.h>
using namespace std;
int main()
{
vector<int> v2;
    int element,size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the element no. "<<i<<" : "<<"\n";
        cin>>element;
        v2.push_back(element);
    }
    for(auto i:v2)
    {
        cout<<i<<" ";
    }


    return 0;
}