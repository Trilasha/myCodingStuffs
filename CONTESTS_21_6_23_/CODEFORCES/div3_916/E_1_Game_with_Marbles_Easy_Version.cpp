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
    vector<ll> a(n),b(n);
    inpv(a);inpv(b);
    ll A=accumulate(all(a),0LL);
    ll B=accumulate(all(b),0LL);
    set<pair<pll,ll>> sa,sb;
    map<ll,pll> mpa,mpb;
    for(ll i=0;i<n;++i){
        sa.insert({{-a[i],-b[i]},i+1});
        sb.insert({{-b[i],-a[i]},i+1});
        mpa[i+1]={-a[i],-b[i]};
        mpb[i+1]={-b[i],-a[i]};
    }
    ll ind=0;
    while(1){
        ind++;
        if(ind==n+1)break;


        //alice turn 
        auto it=sb.begin();
        pair<pll,ll> y=*it;
        pll p1=y.ff;
        ll aval=abs(p1.ss);
        ll bval=abs(p1.ff);
        ll index=y.ss;
        sb.erase(it);

        B-=bval;
        A-=1;
        // mpb[index]={-(aval-1),0};

        pll x=mpa[index];
        sa.erase(sa.find({x,index}));

        ind++;
        if(ind==n+1)break;

        //bob turn
        it=sa.begin();
        y=*it;
        p1=y.ff;
        aval=abs(p1.ff);
        bval=abs(p1.ss);
        index=y.ss;

        sa.erase(it);
        A-=aval;
        B-=1;
        // mpa[index]={0,-(bval-1)};
        x=mpb[index];
        sb.erase(sb.find({x,index}));
        cout<<A<<" "<<B<<endl;
    }
    cout<<A-B<<endl;
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

