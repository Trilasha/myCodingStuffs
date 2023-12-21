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
   ll a,b;
   cin>>a>>b;
   ll kx,ky,qx,qy;
   cin>>kx>>ky>>qx>>qy;
   vector<pll> king,queen;
   king.pb({kx+b,ky+a});
   king.pb({kx-b,ky+a});
   king.pb({kx+b,ky-a});
   king.pb({kx-b,ky-a});
   king.pb({kx+a,ky+b});
   king.pb({kx+a,ky-b});
   king.pb({kx-a,ky+b});
   king.pb({kx-a,ky-b});

   queen.pb({qx+b,qy+a});
   queen.pb({qx-b,qy+a});
   queen.pb({qx+b,qy-a});
   queen.pb({qx-b,qy-a});
   queen.pb({qx+a,qy+b});
   queen.pb({qx+a,qy-b});
   queen.pb({qx-a,qy+b});
   queen.pb({qx-a,qy-b});

   set<pll> st;
   for(ll i=0;i<8;++i){
    for(ll j=0;j<8;++j){
        if(king[i]==queen[j]){
            st.insert(king[i]);
        }
    }
   }
   cout<<st.size()<<endl;


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

