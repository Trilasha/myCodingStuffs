#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

const int N = 100005;
int f[N],invf[N];

int power(int a,int b)
{
    if(b==0)
        return 1;
    else
    {
        int x=power(a,b/2);
        int y=(x*x)%MOD;
        if(b%2)
            y=(y*a)%MOD;
        return y;
    }
}

int inverse(int a)
{
    return power(a,MOD-2);
}

void precompute()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=(f[i-1]*i)%MOD;
    for(int i=0;i<N;i++)
        invf[i]=inverse(f[i]);
}

void solve(int tc)
{
    int n;
    cin >> n;
    map<int,int> c;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        c[x]++;
    }
    int num = 1;
    for(auto z:c)
    {
        num = (num*f[z.second])%MOD;
    }
    int den = f[n];
    cout<<num<<endl;
    cout<<inverse(den)<<endl;
    int ans = (num*inverse(den))%MOD;
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int tc=1;
    // cin >> tc;
    for(int ttc=1;ttc<=tc;ttc++)
        solve(ttc);
    return 0;
}
