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
   ll q,s;
   cin>>q>>s;
   while(q--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        inpv(v);
        sort(all(v));
        if(s==0){
            ll ans=0;
            if(n%2){
                for(ll i=0;i<=n/2;++i){
                    ans+=v[i];
                }
                cout<<ans<<endl;
            }else{
                for(ll i=1;i<=n/2;++i){
                    ans+=v[i];
                }
                cout<<ans<<endl;
            }
        }else{
            ll ans=v.back();
            ll ind=0,curr=0,sum=0;
            ll j=n-1;
            for(ll i=n-1;i>=0;--i){
                sum+=v[i];
                ind++;
                if(ind%2 && ind>1){
                    curr+=v[j];
                    j--;
                    ans=max(ans,sum-curr);
                }
            }
            cout<<ans<<endl;
        }
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

