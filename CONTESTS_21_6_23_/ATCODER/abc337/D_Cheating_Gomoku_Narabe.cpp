/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<string> v(n);
    fr(i,n){
       cin>>v[i];
    }
    ll ans=1e18;
    vector<vector<ll>> row(n+1),col(m+1);
    for(ll i=0;i<n;++i){
        string s=v[i];
        for(ll j=0;j<s.size();++j){
            if(s[j]=='x'){
                row[i].pb(j);
                col[j].pb(i);
            }
        }
    }
    for(ll i=0;i<n;++i){
        deque<ll> dq;
        for(auto &j:row[i]){
            dq.pb(j);
        }
        if(dq.empty() || dq[0]!=0)dq.push_front(-1);
        if(dq.size()==1 || dq.back()!=m-1)dq.push_back(m);
        for(ll j=1;j<dq.size();++j){
            ll prev=dq[j-1];
            ll curr=dq[j];
            curr--;
            prev++;
            ll len=curr-prev+1;
            if(len<k)continue;
            ll dot=0;
            for(ll x=prev;x<prev+k;++x){
                if(v[i][x]=='.')dot++;
            }
            ans=min(ans,dot);
            for(ll x=prev+k;x<=curr;++x){
                if(v[i][x]=='.')dot++;
                if(v[i][x-k]=='.')dot--;
                ans=min(ans,dot);
            }
        }
    }

    for(ll i=0;i<m;++i){
        deque<ll> dq;
        for(auto &j:col[i]){
            dq.pb(j);
        }
        if(dq.empty() || dq[0]!=0)dq.push_front(-1);
        if(dq.size()==1 || dq.back()!=n-1)dq.push_back(n);
        for(ll j=1;j<dq.size();++j){
            ll prev=dq[j-1];
            ll curr=dq[j];
            curr--;
            prev++;
            ll len=curr-prev+1;
            if(len<k)continue;
            ll dot=0;
            for(ll x=prev;x<prev+k;++x){
                if(v[x][i]=='.')dot++;
            }
            ans=min(ans,dot);
            for(ll x=prev+k;x<=curr;++x){
                if(v[x][i]=='.')dot++;
                if(v[x-k][i]=='.')dot--;
                ans=min(ans,dot);
            }
        }
    }
    cout<<((ans==1e18)?-1:ans)<<endl;
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

