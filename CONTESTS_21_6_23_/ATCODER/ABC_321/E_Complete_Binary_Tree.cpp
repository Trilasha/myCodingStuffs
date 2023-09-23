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





 
ll bpow(ll base,ll power){ll res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}

ll calc(ll val){
    ll cnt=0;
    while(val>1){
        val>>=1;
        cnt++;
    }
    return cnt;
}
void solve(){
    ll t;
    cin>>t;

    for(ll i=0;i<t;++i){

        ll n,x,k;
        cin>>n>>x>>k;
        
        ll mx_depth=log2(n);
        ll ans=0;
        ll depth=log2(x);
        ll dis=depth+k;
        //cout<<mx_depth<<" "<<depth<<" "<<dis<<endl;
        if(dis<=mx_depth){
            ll start=bpow(2,dis);
            ll end=2*start-1;
            ll mid=(start+end)/2;
            if(mid<=n){
                ans+=max(0ll,(mid-start+1));
            }else{
                ans+=max(0ll,(n-start+1));
            }
        }

        if(k<=depth && k>0)ans++;
        else if(k>depth && (k-depth)<=mx_depth){
            //cout<<dis<<endl;
            dis=k-depth;
            ll start=bpow(2,dis);
            ll end=2*start-1;
            ll mid=(start+end)/2;
            ll new_s=mid+1;
            if(new_s<=n && end<=n){
                ans+=(end-new_s+1);
            }else if(new_s<=n){
                ans+=(n-new_s+1);
            }
        }
        cout<<ans<<endl;
    }
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

