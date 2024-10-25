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




/*
(2k-2) =  A
At + A+2+x=n
A(t+1)=n-x+2;

*/
void solve(){
    ll n,x;
    cin>>n>>x;
    set<ll> st;
    ll chk=n+x-2;
    for(ll i=1;i*i<=chk+1;i++){
        if((chk%i)==0){
            if(!(i%2)){
                ll y=(i+2)/2;
                if(y>=x)
                st.insert(y);
            }
             ll y=chk/i;
             ll d=(y+2)/2;
            if(i!=y && !(y%2) && d>=x)st.insert(d);
        }
    }
    n=n-x;
    // printset(st);code
    for(ll i=1;i*i<=n+1;i++){
        if((n%i)==0){
            if(!(i%2)){
                ll y=(i+2)/2;
                if(y>=x)
                st.insert(y);
            }
             ll y=n/i;
             ll d=(y+2)/2;
            if(i!=y && !(y%2) && d>=x)st.insert(d);
        }
    }
    // if(st.count(1))
    // st.erase(st.find(1));
    // printset(st);
    cout<<st.size()<<endl;
    // line
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

