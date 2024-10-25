/*
    "When you are in darkness, listen to the whispers of your heart
    but when you are in light, listen to the thunder of your brain."
    
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
/*----------------------------------------------------------------------------------------------------------- */





void solve(){
    ll n,s;
    cin>>n>>s;
    if(s%2 || s<n || n==1){
        cout<<-1<<endl;
        return;
    }
    vector<ll> ans;
    if(!(n%2)){
        fr(i,n/2-1){
            ans.pb(1);
        }
        ans.pb(s/2 - (n/2 - 1));
        for(auto &i: ans){
            cout<<i<<" ";
        }
        for(auto &i: ans){
            cout<<i<<" ";
        }   
        cout<<endl;
        return;
    }
    if(n==3){
        ll bit=bpl(s/2);
        if(bit<=1){
            cout<<-1<<endl;
            return;
        }
        for(ll i=30;i>=0;i--){
            if((1LL<<i)&(s/2)){
                ll c=s/2-(1LL<<i);
                cout<<s/2<<" "<<(1LL<<i)<<" "<<c<<endl;
                return;
            }
        }
    }
    if(s<n+3){
        cout<<-1<<endl;
        return;
    }
    cout<<1<<" "<<2<<" "<<3<<" ";
    s-=6,n-=3;
    fr(i,(n/2)-1){
        ans.pb(1);
    }
    ans.pb(s/2 - (n/2 - 1));
    for(auto &i: ans){
        cout<<i<<" ";
    }
    for(auto &i: ans){
        cout<<i<<" ";
    }   
    cout<<endl;
    return;
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

