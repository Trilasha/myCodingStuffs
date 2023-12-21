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






ll printprimefactors(ll n){
    if(n<=1) return -1;
    while(n%2==0)
    {
        return 2;
        n=n/2;
    }
     while(n%3==0)
    {
        return 3;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
            return i;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            return i+2;
            n=n/(i+2);
        }
    }
    if(n>3)
    return n;
    // return;
    //i/p-->450
    //o/p-->23355
    return n;
}
//tc-theta(sqrt(n))

void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<0<<endl;
        return;
    }
    ll one=1;
    ll other=n;
    // if(one==other){
    //     cout<<one<<" "<<0<<endl;
    //     return;
    // }
    ll x=0,y=0;
    // cout<<one<<" "<<other<<endl;
    // line
    for(ll i=0;i<31;++i){
        ll set1=one&(1<<i);
        ll set2=other&(1<<i);
        //cout<<set1<<" "<<set2<<endl;
        if((set1==0 && set2==0) || (set1!=0 && set2!=0)){
            if(set1!=0){
                if(y>x)
                x+=(1<<i);
                else
                y+=(1<<i);
            }
        }else{
             x+=(1<<i);
             y+=(1<<i);
        }
    }
    cout<<x<<" "<<y<<endl;
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

