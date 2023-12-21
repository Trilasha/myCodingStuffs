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
   ll n;
   cin>>n;
   vector<ll> v(n);
   inpv(v);
   map<ll,vector<pll>> mp;
   for(ll i=0;i<n;++i){
        ll sum=0;
        for(ll j=i;j<n;++j){
            sum+=v[j];
            mp[sum].pb({i+1,j+1});
        }
   }
   ll ans=0;
   vector<pll> ans_pairs;
   vector<pll> vp;
   for(auto &i:mp){
        ll curr=i.first;
        vector<pll> pairs=i.second;
        // cout<<curr<<" "<<pairs.size()<<endl;
        sort(all(pairs));
        vector<pll> fin;
        ll mx=pairs[0].ss;
        fin.pb({pairs[0]});
        for(ll j=1;j<pairs.size();++j){
            if(pairs[j].ff>mx){
                fin.pb({pairs[j]});
                mx=pairs[j].ss;
            }else{
                if(pairs[j].ss<mx){
                    fin.pop_back();
                    fin.pb(pairs[j]);
                    mx=pairs[j].ss;
                }
            }
        }
        if(fin.size()>ans){
            ans=fin.size();
            ans_pairs=fin;
        }
   }
   cout<<ans<<endl;
   for(auto &i:ans_pairs){
        cout<<i.ff<<" "<<i.ss<<endl;
   }
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

