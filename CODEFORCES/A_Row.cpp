#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ct=0;

    if(n==1)
    {
        if(s=="0")
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
        return;
    }

    if(n>=2)
    {
        if((s[0]=='0' && s[1]=='0') || (s[s.size()-2]=='0' && s[s.size()-1]=='0'))
        {
            cout<<"No"<<endl;
            return;
        }
    }

    for(int x=0;x<s.size()-1;++x)
    {
        if(s[x]==s[x+1] && s[x]=='1' && s[x+1]=='1')
        {
            cout<<"No"<<endl;
            return;
        }
        else if(s[x]==s[x+1] && s[x]=='0' && s[x+1]=='0' && ct!=0)
        {
            cout<<"No"<<endl;
            return;
        }
        else if(s[x]==s[x+1] && s[x]=='0' && s[x+1]=='0' && ct==0)
        {
            ct+=2;
        }
        else 
            ct=0;
    }


    cout<<"Yes"<<endl;
    return;
}
int main()
{
    solve();
    return 0;
}