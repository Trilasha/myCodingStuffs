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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */





map<char,ll> mp={{'A',1},{'B',10},{'C',100},{'D',1000},{'E',10000}};
ll calc(string s){
    char mx=s[s.size()-1];
    ll val=mp[s[s.size()-1]];
    for(ll i=s.size()-2;i>=0;--i){
        if(s[i]<mx){
            val-=mp[s[i]];
        }else{
            val+=mp[s[i]];
            mx=s[i];
        }
    }

    return val;
}

void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    ll ans=calc(s);

    map<char,ll> left,right;
    for(ll i=0;i<n;++i){
        right[s[i]]=i;
    }
    for(ll i=n-1;i>=0;--i){
        left[s[i]]=i;
    }
    
    //2*25*O(N) approx 
    for(char ch1='A';ch1<='E';++ch1){
        for(char ch2='A';ch2<='E';++ch2){
            //try all the possibilities
            
            //leftmost
            ll ind=left[ch1];
            char ch=s[ind];
            s[ind]=ch2;
            ans=max(ans,calc(s));
            s[ind]=ch;

            //rightmost
            ind=right[ch1];
            ch=s[ind];
            s[ind]=ch2;
            ans=max(ans,calc(s));
            s[ind]=ch;
        }
    }

    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */