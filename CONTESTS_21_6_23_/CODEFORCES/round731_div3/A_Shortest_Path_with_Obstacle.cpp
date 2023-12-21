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
    string s;
    getline(cin, s);
    ll x1, y1, x2, y2, fx, fy;
    cin>>x1>>y1>>x2>>y2>>fx>>fy;
    if(x1==x2){
        ll add=abs(y1-y2);
        if((y2>y1 && fy>y1 && fy<y2 && fx==x1) || (y2<y1 && fy<y1 && fy>y2 && fx==x1)){
            add+=2;
        }
        cout<<add<<endl;
        return;
    }
    if(y1==y2){
        ll add=abs(x1-x2);
        if((x2>x1 && fx>x1 && fx<x2 && fy==y1) || (x2<x1 && fx<x1 && fx>x2 && fy==y1)){
            add+=2;
        }
        cout<<add<<endl;
        return;
    }
    cout<<abs(x1-x2)+abs(y1-y2)<<endl;
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

