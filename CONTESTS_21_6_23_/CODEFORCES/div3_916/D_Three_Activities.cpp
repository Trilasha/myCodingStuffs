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
    vector<ll> a(n),b(n),c(n);
    inpv(a);inpv(b);inpv(c);
    set<pll> sta,stb,stc;
    for(ll i=0;i<n;++i){
        sta.insert({a[i],i});
        stb.insert({b[i],i});
        stc.insert({c[i],i});
    }
    ll ans=0;
    for(ll i=0;i<n;++i){

        //abc
        ll curr=a[i];
        pll p1={b[i],i};
        pll p2={c[i],i};
        stb.erase(stb.find(p1));
        stc.erase(stc.find(p2));

        pll val=*stb.rbegin();
        curr+=val.ff;
        ll ind=val.ss;
        pll p3={c[ind],ind};
        stc.erase(stc.find(p3));
        val=*stc.rbegin();
        curr+=val.ff;
        stc.insert(p3);

        ans=max(ans,curr);

        //acb
        curr=a[i];
        val=*stc.rbegin();
        curr+=val.ff;
        ind=val.ss;
        p3={b[ind],ind};
        stb.erase(stb.find(p3));
        val=*stb.rbegin();
        curr+=val.ff;
        stb.insert(p3);
        ans=max(ans,curr);

        stb.insert(p1);
        stc.insert(p2);
    //  cout<<ans<<endl;
    }
     for(ll i=0;i<n;++i){

        //bac
        ll curr=b[i];
        pll p1={a[i],i};
        pll p2={c[i],i};
        sta.erase(sta.find(p1));
        stc.erase(stc.find(p2));

        pll val=*sta.rbegin();
        curr+=val.ff;
        ll ind=val.ss;
        pll p3={c[ind],ind};
        stc.erase(stc.find(p3));
        val=*stc.rbegin();
        curr+=val.ff;
        ans=max(ans,curr);
        stc.insert(p3);

        //bca
        curr=b[i];
        val=*stc.rbegin();
        curr+=val.ff;
        ind=val.ss;
        p3={a[ind],ind};
        sta.erase(sta.find(p3));
        val=*sta.rbegin();
        curr+=val.ff;
        ans=max(ans,curr);
        sta.insert(p3);

        sta.insert(p1);
        stc.insert(p2);
    }
     for(ll i=0;i<n;++i){
        //cab
        ll curr=c[i];
        pll p1={a[i],i};
        pll p2={b[i],i};
        sta.erase(sta.find(p1));
        stb.erase(stb.find(p2));
        pll val=*sta.rbegin();
        curr+=val.ff;
        ll ind=val.ss;
        pll p3={b[ind],ind};
        stb.erase(stb.find(p3));
        val=*stb.rbegin();
        curr+=val.ff;
        ans=max(ans,curr);
        stb.insert(p3);

        //cba
        curr=c[i];
        val=*stb.rbegin();
        curr+=val.ff;
        ind=val.ss;
        p3={a[ind],ind};
        sta.erase(sta.find(p3));
        val=*sta.rbegin();
        curr+=val.ff;
        ans=max(ans,curr);
        sta.insert(p3);

        sta.insert(p1);
        stb.insert(p2);
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

