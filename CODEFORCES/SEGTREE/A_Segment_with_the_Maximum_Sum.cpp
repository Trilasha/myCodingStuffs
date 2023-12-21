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






struct item{
    ll seg,pref,suff,sum;
};

struct segtree{
    ll size;
    vector<item> values;

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,{0,0,0,0});
    }
    item merge(item a, item b){
        return {
            max({a.seg,b.seg,a.suff+b.pref}),
            max(a.pref,a.sum+b.pref),
            max(b.suff,b.sum+a.suff),
            a.sum+b.sum
        };
    }
    item single(ll v){
        if(v>0){
            return {v,v,v,v};
        }
        else{
            return {0,0,0,v};
        }
    }
    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            values[x]=single(v);
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(ll index,ll val){
        set(index,val,0,0,size);
    }
    item calc(ll l,ll r,ll x,ll lx,ll rx){
        if(lx>=r || l>=rx) return {0,0,0,0};
        if(lx>=l && rx<=r) return values[x];
        ll m=(lx+rx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item calc(ll l,ll r){
        return calc(l,r,0,0,size);
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    segtree st;
    st.init(n);
    fr(i,n){
        cin>>v[i];
        st.set(i,v[i]);
    }
    cout<<st.calc(0,n).seg<<endl;
    while(q--){
        ll index,val;
        cin>>index>>val;
        st.set(index,val);
        cout<<st.calc(0,n).seg<<endl;
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

