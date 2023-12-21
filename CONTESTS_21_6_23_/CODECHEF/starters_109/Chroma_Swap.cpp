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
   vector<ll> a(n),cola(n),b(n),colb(n);
   inpv(a);inpv(cola);inpv(b);inpv(colb);
   map<ll,multiset<ll>> mp;
   map<ll,ll> chka,chkb;
   for(ll i=0;i<n;++i){
    chka[cola[i]]++;
    chkb[colb[i]]++;
   }
   vector<ll> vis(2*n+10);
   for(ll i=0;i<n;++i){
    if(chkb.count(cola[i])){
        vis[cola[i]]=1;
        mp[cola[i]].insert(a[i]);
    }
    if(chka.count(colb[i])){
        vis[colb[i]]=1;
        mp[colb[i]].insert(b[i]);
    }
   }

   ll prev=0;
   for(ll i=0;i<n;++i){
    ll curr=-1;
    if(!vis[cola[i]]){
        curr=a[i];
    }else{
        auto it=mp[cola[i]].lower_bound(prev);
        if(it!=mp[cola[i]].end()){
            curr=*it;
            mp[cola[i]].erase(mp[cola[i]].find(*it));
        }
    }
    // for(auto &j:mpa[cola[i]]){
    //     cout<<j<<" ";
    // }
    if(curr<prev){
        cout<<"No"<<endl;
        return;
    }
    prev=curr;
   }
   cout<<"Yes"<<endl;
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

