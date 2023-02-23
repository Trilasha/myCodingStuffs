#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(auto &x:v)
    cin>>x;

    int ans=1;
    int temp=0;

    for(int x=0;x<k;++x)
    temp+=v[x];

    int curr=temp;
    int ind=0;

    for(int x=k;x<n;++x)
    {
        temp-=v[ind++];
        temp+=v[x];
        if(temp<curr)
        {
            curr=temp;
            ans=x-k+2;
        }
    }

    cout<<ans<<endl;

    return 0;
}