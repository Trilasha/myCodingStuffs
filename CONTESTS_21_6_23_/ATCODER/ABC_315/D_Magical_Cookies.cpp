/* Trilasha Mazumder */

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




void solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<char>> v(n,vector<char>(m));
  fr(i,n){
    fr(j,m){
        cin>>v[i][j];
    }
  }
  vector<vector<ll>> vis(n,vector<ll>(m,0));
  
  for(ll i=0;i<n;++i){
        set<ll> st;
        vector<ll> vv(26);
        for(ll j=0;j<m;++j){
            vv[v[i][j]-'a']++;
        }
        ll ok=0;
        ll ind=-1;
        for(ll i=0;i<26;++i){
            if(vv[i]){
                ind=i;
                ok++;
            }
        }
        if(ok>1) break;
        if(vv[ind]<=1) break;
        for(ll j=0;j<m;++j){
            vis[i][j]=1;
        }
    }

     for(ll i=0;i<m;++i){
        set<ll> st;
        vector<ll> vv(26);
        ll ind=-1;
        for(ll j=0;j<n;++j){
            if(!vis[j][i])
            vv[v[j][i]-'a']++;
        }
        ll ok=0;
        for(ll i=0;i<26;++i){
            if(vv[i]){
                ind=i;
                ok++;
            }
        }
        if(ok>1) break;
        if(vv[ind]<=1){
            ll cnt=0;
            for(ll j=0;j<n;++j){
                if(vis[j][i] && v[j][i]==char(ind+'a'))cnt++;
            }
            if(cnt==0) break;
        }
        for(ll j=0;j<n;++j){
            vis[j][i]=1;
        }
    }

    ll ans=0;
    fr(i,n){
        fr(j,m){
            if(!vis[i][j])ans++;
        }
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}




   
