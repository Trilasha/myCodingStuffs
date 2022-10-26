#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2ll);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    for(int q=1;q<=t;q++){
        cout<<"Case #"<<q<<": ";
        vector <pair<int,int>> v;
        vector <pair<string,int>> a;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            int d,u;
            cin>>d>>u;
            v.push_back({d,u});
            a.push_back({s,u});
        }
        sort(v.begin(),v.end());
        sort(a.begin(),a.end());
        for(auto &i:v)
    cout<<i.first<<" "<<i.second<<endl;
     for(auto &i:a)
    cout<<i.first<<" "<<i.second<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i].ss==a[i].ss)
                ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}