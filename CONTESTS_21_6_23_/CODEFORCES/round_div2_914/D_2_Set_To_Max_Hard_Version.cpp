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
   set<ll> st;
   deque<ll> dq;
   for(ll i=0;i<n;++i){
        if(a[i]>b[i]){
            cout<<"NO"<<endl;
            return;
        }
   }
   for(ll i=0;i<n;++i){
        while(!dq.empty() and dq.back()<a[i]){
            ll val=dq.back();
            dq.pop_back();
            st.erase(st.find(val));
        }
        if(!st.count(a[i])){
            dq.pb(a[i]);
            st.insert(a[i]);
        }
        // if(a[i]==b[i])continue;
        // if(st.count(b[i])){
        //     a[i]=b[i];
            while(!dq.empty() and dq.front()>b[i]){
                ll val=dq.front();
                dq.pop_front();
                st.erase(st.find(val));
            }
            if(!dq.empty() && dq.front()==b[i])a[i]=b[i];
   }
    dq.clear();
    st.clear();
    // printv(a);
    for(ll i=n-1;i>=0;--i){
        while(!dq.empty() and dq.back()<a[i]){
            ll val=dq.back();
            dq.pop_back();
            st.erase(st.find(val));
        }
        if(!st.count(a[i])){
            dq.pb(a[i]);
            st.insert(a[i]);
        }
    while(!dq.empty() and dq.front()>b[i]){
        ll val=dq.front();
        dq.pop_front();
        st.erase(st.find(val));
    }
    if(!dq.empty() && dq.front()==b[i])a[i]=b[i];
   }
   cout<<((a==b)?"YES":"NO")<<endl;

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

