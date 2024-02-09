/*
    Unsolved count 24
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
    ll n,x;
    cin>>n>>x;
    stack<ll> st1,st2,st3;
    vector<ll> a(n),b(n),c(n);
    inpv(a);inpv(b);inpv(c);
    for(ll i=n-1;i>=0;--i){
        st1.push(a[i]);
        st2.push(b[i]);
        st3.push(c[i]);
    }
    ll ans=0;
    ll ok=0;
    ll chk=0;
 
    while(1){
        chk=0;
        ok=0;
        if(st1.empty() && st2.empty() && st3.empty()){
            break;
        }
        //line
        if(ans==x){
            cout<<"Yes"<<endl;
            return;
        }
        ll val=0;
        if(!st1.empty()){
            val=st1.top();
            for(ll i=0;i<=31;++i){
                if(!(x&(1LL<<i))){
                    if(val&(1LL<<i)){
                        // cout<<i<<" ";
                        ok=1;
                        break;
                    }
                }
            }
        }
        if(!ok && !st1.empty()){
            chk=1;
            ans|=val;
            st1.pop();
        }
        if(ans==x){
            cout<<"Yes"<<endl;
            return;
        }
        // cout<<ans<<endl;
        //
        ok=0;
        val=0;
       if(!st2.empty()){
            val=st2.top();
            for(ll i=0;i<=31;++i){
                if(!(x&(1LL<<i))){
                    if(val&(1LL<<i)){
                        // cout<<i<<" ";
                        ok=1;
                        break;
                    }
                }
            }
        }
        if(!ok && !st2.empty()){
            chk=1;
            ans|=val;
            st2.pop();
        }
        if(ans==x){
            cout<<"Yes"<<endl;
            return;
        }
        // cout<<ans<<endl;
 
        //
        ok=0;
        val=0;
        if(!st3.empty()){
            val=st3.top();
            for(ll i=0;i<=31;++i){
                if(!(x&(1LL<<i))){
                    if(val&(1LL<<i)){
                        ok=1;
                        break;
                    }
                }
            }
        }
        if(!ok && !st3.empty()){
            chk=1;
            ans|=val;
            st3.pop();
        }
        if(ans==x){
            cout<<"Yes"<<endl;
            return;
        }
        // cout<<ans<<endl;
        // line
        if(!chk){
            cout<<"No"<<endl;
            return;
        }
    }
 
    cout<<((ans==x)?"Yes":"No")<<endl;
 
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

