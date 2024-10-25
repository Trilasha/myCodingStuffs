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




struct segtreeMin{
    vector<ll> v;ll id=1e12,sz;//id for initialization
    segtreeMin(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
    ll func(ll x,ll y){ return min(x,y);}
    void pull(ll x){ v[x]=func(v[2*x+1],v[2*x+2]);}
    void update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
        if(rx-lx==1){ v[x]=val; return;}
        ll m=(lx+rx)/2;
        if(i<m){update(i,val,2*x+1,lx,m);}
        else{update(i,val,2*x+2,m,rx);}
        pull(x);
    }
    void update(ll i, ll val){ update(i,val,0,0,sz);}
    ll query(ll l,ll r,ll x,ll lx,ll rx){ // [l,r) l->INCLUSIVE/ r->EXCLUSIVE
        if(lx>=r || l>=rx) return id;
        if(lx>=l && rx<=r) return v[x];
        ll m=(lx+rx)/2;
        ll s1=query(l,r,2*x+1,lx,m);
        ll s2=query(l,r,2*x+2,m,rx);
        return func(s1,s2);
    }
    ll query(ll l,ll r){ return query(l,r,0,0,sz);}
};
struct segtreeMax{
    vector<ll> v;ll id=INT_MIN,sz;//id for initialization
    segtreeMax(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
    ll func(ll x,ll y){ return max(x,y);}
    void pull(ll x){ v[x]=func(v[2*x+1],v[2*x+2]);}
    void update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
        if(rx-lx==1){ v[x]=val; return;}
        ll m=(lx+rx)/2;
        if(i<m){update(i,val,2*x+1,lx,m);}
        else{update(i,val,2*x+2,m,rx);}
        pull(x);
    }
    void update(ll i, ll val){ update(i,val,0,0,sz);}
    ll query(ll l,ll r,ll x,ll lx,ll rx){ // [l,r) l->INCLUSIVE/ r->EXCLUSIVE
        if(lx>=r || l>=rx) return id;
        if(lx>=l && rx<=r) return v[x];
        ll m=(lx+rx)/2;
        ll s1=query(l,r,2*x+1,lx,m);
        ll s2=query(l,r,2*x+2,m,rx);
        return func(s1,s2);
    }
    ll query(ll l,ll r){ return query(l,r,0,0,sz);}
};

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> pref,suff;
    ll sum=0;
    fr(i,n){
        sum+=v[i];
        pref.pb(sum);
    }
    sum=0;
    for(ll i=n-1;i>=0;--i){
        sum+=v[i];
        suff.pb(sum);
    }
    segtreeMin st(n);
    segtreeMax st2(n);
    fr(i,n){
        st.update(i,v[i]);
        st2.update(i,v[i]);
    }
    vector<ll> samePref(n+1),sameSuff(n+1);
    samePref[0]=0;
    for(ll i=1;i<n;++i){
        if(v[i]==v[i-1])samePref[i]=samePref[i-1];
        else samePref[i]=i;
    }
    sameSuff[n-1]=n-1;
    for(ll i=n-2;i>=0;--i){
        if(v[i]==v[i+1])sameSuff[i]=sameSuff[i+1];
        else sameSuff[i]=i;
    }
    // printv(samePref);
    // printv(sameSuff);
    vector<ll> ans;
    for(ll i=0;i<n;++i){
        ll need=pref[i]+v[i];
        ll op1=-1,op2=-1;
        if((i>0 && v[i]<v[i-1]) || (i<(n-1) && v[i]<v[i+1])){
            ans.pb(1);
            continue;
        }
        ll ind=ub(all(pref),need)-pref.begin();
        // cout<<ind<<" ";
        if(ind<n && sameSuff[i+1]!=(n-1)){
            ll mn=st.query(i+1,ind+1);
            ll mx=st2.query(i+1,ind+1);
            if(mn!=mx || mn>v[i]){
                op1=ind-i;
            }
            // if(sameSuff[i+1]!=n-1){
            op1=max(op1,sameSuff[i+1]+1-i);
            // }
        }
        need=suff[n-i-1]+v[i];
        ind=ub(all(suff),need)-suff.begin();
        // cout<<i<<"->"<<ind<<endl;
        if(ind<n && samePref[i-1]!=0){
            ll right=n-ind-1;
            ll mn=st.query(right,i);
            ll mx=st2.query(right,i);
            // cout<<right<<" "<<mn<<" "<<mx<<endl;
            if(mn!=mx || mn>v[i]){
                op2=i-right;
            }
            // if(i>0 && samePref[i-1]!=0){
                op2=max(op2,i-samePref[i-1]+1);
            // }
        }
        if(op1==-1 && op2==-1){
            ans.pb(-1);
        }else{
            if(op1==-1)ans.pb(op2);
            else if(op2==-1)ans.pb(op1);
            else ans.pb(min(op1,op2));
        }
    }
    printv(ans);
 
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

