#include<bits/stdc++.h>
#define int long long
using namespace std ;

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int x=a[0],y=a[0],z=0;
        for(int i=1;i<n;i++)
        {
            if(x<0)
            {
                x=0;
            }
            if((abs(a[i-1]%2))==(abs(a[i]%2)))
            x=a[i];
            else
            x=x+a[i];
           y=max(y,x);
        }
        cout<<y<<"\n";

    }
    return 0;
}
