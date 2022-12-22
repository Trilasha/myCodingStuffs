#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    int t[m+1][n+1];

    //initialization
    //fill the table as done earlier for longest lcs

    int x=m,y=n;
    string ans="";
    while(x>0 && y>0)
    {
        if(s1[x-1]==s2[y-1])
        {
            ans+=s1[x-1];
            x--;
            y--;
        }
        else if(t[x][y-1]>t[x-1][y])
        y--;
        else
        x--;
    }

    return ans;
    return 0;
}