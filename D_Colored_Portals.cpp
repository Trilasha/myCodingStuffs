/** Let it hurt then let it go.. */

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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
/*----------------------------------------------------------------------------------------------------------- */




//  BG, BR, BY, GR, GY, or RY
vector<string> v={"BG","BR","BY","GR","GY","RY"};
void solve(){
   ll n,q;
   cin>>n>>q;
   map<ll,string> mp1;
   map<string,set<ll>> mp2;
   fr(i,n){
        string s;
        cin>>s;
        mp1[i+1]=s;
        mp2[s].insert(i+1);
   }
   fr(i,q){
        ll x,y;
        cin>>x>>y;
        set<char> st;
        for(auto ch:mp1[x]){
            st.insert(ch);
        }
        for(auto ch:mp1[y]){
            st.insert(ch);
        }
        if(st.size()<4){
            cout<<abs(x-y)<<endl;
        }else{
            if(x>y)swap(x,y);
            string xx=mp1[x];
            string yy=mp1[y];  
            ll ans=INT_MAX;
            for(auto &s:v){
                if(s==xx || s==yy || mp2[s].empty())continue;
                auto it=mp2[s].ub(x);
                if(it!=mp2[s].end()){
                    ans=min(ans,*it-x + abs(y-*it));
                }
                it=mp2[s].ub(y);
                if(it!=mp2[s].begin()){
                    it--;
                    ans=min(ans,y-*it + abs(x-*it));
                }
            }
            cout<<((ans==INT_MAX)?-1:ans)<<endl;
        }
   }

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