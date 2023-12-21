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






vector<ll> ans;
void kmp(string s,string t){
    ll n=s.size();
    ll m=t.size();
    vector<ll> lps(m);
    ll i=1,j=0;
    while(i<m){
        if(t[i]==t[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            ans.pb(i);
            j=lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}
void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    kmp(s,t);
    while(q--){
        ll l,r;
        cin>>l>>r;
        //printv(ans);
        ll ind=lb(all(ans),r)-ans.begin();
        if(ind<ans.size() && ans[ind]==r){
            ind++;
        }
        ll ind2=lb(all(ans),l+m-1)-ans.begin();
        cout<<max(0ll,ind-ind2)<<endl;
    }

}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

