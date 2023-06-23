/* ...  risen_ash  ... */

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





map<ll,char> mp={{1,'a'},{2,'b'},{3,'a'},{4,'c'},{5,'a'},{6,'b'},{7,'a'}};
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll ok=0;
    ll cnt=0;

    for(ll i=0;i<=n-7;++i){
        ok=0;
        for(ll j=i;j<i+7;++j){
            if(s[j]!=mp[j-i+1]){
                ok=1;
                break;
            }
        }
        if(!ok)
        cnt++;
    }

    if(cnt>1){
        cout<<"No"<<endl;
        return;
    }

    if(cnt==1){
        cout<<"Yes"<<endl;
        for(ll i=0;i<n;++i){
            if(s[i]=='?')s[i]='z';
        }
        cout<<s<<endl;
        return;
    }


    for(ll i=0;i<=n-7;++i){
        ll ok=0;
        string temp=s;


        for(ll j=i;j<i+7;++j){
            if(s[j]!=mp[j-i+1] && s[j]!='?'){
                ok=1;
                break;
            }
            temp[j]=mp[j-i+1];
        }

        if(ok==1)continue;

        ll chk=0;
        ll entered=0;

        for(ll k=0;k<=n-7;++k){
            //cout<<k<<endl;
            if(k==i)continue;
            entered=1;
            chk=0;
            for(ll j=k;j<k+7;++j){
                if(temp[j]!=mp[j-k+1]){
                    chk=1;
                    break;
                }
            }
            if(!chk){
                break;
            }
        }

        if(!entered)chk=1;

        if(chk){
            //found;
            for(ll k=i;k<i+7;++k){
                s[k]=mp[k-i+1];
            }
            for(ll k=0;k<n;++k){
                if(s[k]=='?')s[k]='z';
            }
            cout<<"Yes"<<endl;
            cout<<s<<endl;
            return;
        }

    }

    cout<<"No"<<endl;



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