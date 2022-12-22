//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x=m;
    int y=n;

    //string a,b;
    //a's size --> m
    //b's size --> n

    string ans="";

    while(x>0 && y>0)
    {
        if(a[x-1]==b[y-1])
        {
            ans.push_back(a[x-1]);
            x--;
            y--;
        }
        else if(t[x][y-1]>t[x-1][y])
        {
            ans.push_back(b[y-1]);
            y--;
        }
        else
        {
            ans.push_back(a[x-1]);
            x--;
        }
    }


    if(x>0)
    {
        ans.push_back(a[x-1]);
        x--;
    }

    if(y>0)
    {
        ans.push_back(b[y-1]);
        y--;
    }
    return 0;
}