#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

 vector<int> a={5, 9, 15, 20};
 vector<int> b={1, 3, 6, 8, 19, 35,0,0,0,0};

 for(int x=0;x<a.size();++x)
 {
    int key=a[x];
    int j=0;
    while(b[j]<key)
    {
        j++;
    }

    int ind=b.size()-1;
    while(ind>j)
    {
        b[ind]=b[ind-1];
        ind--;
    }

    b[ind]=key;
 }

 for(int x=0;x<b.size();++x)
 cout<<b[x]<<" ";

    return 0;
}

// better tc
// https://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/