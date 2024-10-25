/*
    Trilasha Mazumder
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





void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    inpv(v);
    vector<ll> a(m),b(k);
    inpv(a);inpv(b);
    sort(all(a));
    sort(all(b));
    sort(all(v));
    ll mx=0;ll st=0;
    map<ll,ll> mp;
    vector<ll> d;
    ll sec=0;
    for(ll i=0;i<n-1;++i){
        ll diff=v[i+1]-v[i];
        mp[diff]++;
        d.pb(diff);
        if(diff>mx){
            //sec=mx;
            mx=diff;
            st=v[i];
        }
    }
    if(mp[mx]>1){
        cout<<mx<<endl;
        return;
    }
    sec=0;
    sort(all(d));
    d.pop_back();
    if(!d.empty())
    sec=d.back();
    ll ans=mx;
    // cout<<st<<" "<<mx<<endl;
    for(ll i=0;i<m;++i){
        ll src=st-a[i];
        ll ind1=-1,ind2=-1;
        ll ind=lb(all(b),src)-b.begin();
        if(ind!=k && (b[ind]+a[i])<=(st+mx)){
            ind1=ind;
        }
        src=st+mx-a[i];
        ind=lb(all(b),src)-b.begin();
        ind--;
        if(ind>=0 && (b[ind]+a[i])>=st){
            ind2=ind;
        }
        // if(ind1!=-1 && ind2!=-1)
        // cout<<b[ind1]<<" "<<b[ind2]<<endl;
        ll ch=mx;
        if(ind1!=-1){
            ch=min(ch,max(a[i]+b[ind1]-st,st+mx-(a[i]+b[ind1])));
        }
        if(ind2!=-1){
            ch=min(ch,max(a[i]+b[ind2]-st,st+mx-(a[i]+b[ind2])));
            // cout<<ch<<endl;
        }
        if(ind1!=-1 && ind2!=-1){
            ll len=ind2-ind1;
            if(len%2){
                ll mid=(ind1+ind2)/2;
                ch=min(ch,max(a[i]+b[mid]-st,st+mx-a[i]-b[mid]));
                mid++;
                ch=min(ch,max(a[i]+b[mid]-st,st+mx-a[i]-b[mid]));
            }else{
                ll mid=(ind1+ind2)/2;
                ch=min(ch,max(a[i]+b[mid]-st,st+mx-a[i]-b[mid]));
            }
        }
        //cout<<ch<<endl;
        ans=min(ch,ans);
        //line
    }
    //cout<<ans<<" "<<sec<<endl;
    if(ans<sec)ans=sec;
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

