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
    ll n,k;
    cin>>n>>k;
    ll mn=2*(n/2)+(n/2);
    if(mn>k){
        cout<<-1<<endl;
        return;
    }
    vector<ll> v(n);
    for(ll i=0;i<n;i+=2){
        v[i]=1;
        v[i+1]=2;
        k-=3;
    }
    if(k%2){
        cout<<-1<<endl;
        return;
    }
    sort(all(v));
    for(ll i=0;i<n;++i){
        ll rem=100000-v[i];
        ll pos=rem/2;
        if(k>(2*pos)){
            v[i]+=pos*2;
            k-=pos*2;
        }else{
            v[i]+=k;
            k=0;
            break;
        }
    }
    if(k>0){
        cout<<-1<<endl;
        return;
    }
    printv(v);
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

