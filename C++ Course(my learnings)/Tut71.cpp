//Vector in C++ STL
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
       // cout<<v[i]<<" ";
        cout<<v.at(i)<<" ";  //both will give the same results 
    }
    cout<<endl;
}
int main()
{
 vector<int> vec1;
int element,size;
cout<<"Enter the size of your vector"<<endl;
cin>>size;
for (int i = 0; i < size; i++)
{
   cout<<"Enter an element to add to this vector: ";
   cin>>element;
   vec1.push_back(element);
}
display(vec1);

//.vec1.pop_back();
//.display(vec1);

vector<int> :: iterator iter=vec1.begin();
vec1.insert(iter,9,566); //iter+1,iter+2,iter+3,etc....//To insert multiple copies value can be written by giving brackets
display(vec1);
    return 0;
}