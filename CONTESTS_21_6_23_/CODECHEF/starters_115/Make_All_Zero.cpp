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
    multiset<ll> st;
    for(ll i=0;i<n;++i){
        st.insert(v[i]);
    }
    ll ans=0;
    ll mn=v.back();
    ll curr=0;
    ll prev=mn;

    for(ll i=n-1;i>=0;--i){
        mn=min(mn,v[i]);
        st.erase(st.find(v[i]));
        ll x=1e10;
        if(!st.empty()){
            x=*st.begin();
        }
        if(i>0 && x>mn){
            ll add=max(0ll,mn-curr);
            ans+=add;
            curr+=add;
            // v[i]=0;
            prev=mn;
            mn=1e10;
        }else if(i>0 && x<mn){
            // v[i]=0;
            prev=mn;
            mn=1e10;
            ans++;
        }else if(x==mn || i==0){
                if(i==0 && prev>mn && v[i]>0){
                    ans++;
                    continue;
                }
                v[i]-=max(0LL,mn-curr);
                if(i==0 && prev==mn){
                    ans+=mn;
                    continue;
                }
                if(v[i]>0){
                    ans++;
                }   
        }
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

