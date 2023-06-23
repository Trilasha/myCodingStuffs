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





ll calc(string s){
    ll num=0;
    ll ct=1;
    for(ll i=s.size()-1;i>=0;--i){
        num+=(s[i]-'0')*ct;
        ct*=10;
    }
    return num;
}

void solve(){
    ll n;
    cin>>n;
    string s=to_string(n);
    ll ans=0;

    while(s.size()%2==0){
        while(1){
            string left=s.substr(0,s.size()/2);
            string right=s.substr(s.size()/2);
            //cout<<left<<" "<<right<<endl;
            if(left==right){
                ans++;
                s=left;
                break;
            }else{
                ll curr=calc(s);
                curr++;
                s=to_string(curr);
                ans++;
            }
        }
    }

    string temp="";
    for(ll i=0;i<s.size();++i){
        temp.pb('9');
    }
    ll temp_num=calc(temp);
    ll curr_num=calc(s);
    ans+=(temp_num-curr_num);

    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
//cin>>q;
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