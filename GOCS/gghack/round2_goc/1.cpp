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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */




    ll recur(int n, vector<int>v,int mx){
    vector<int>odd,even;
    ll ans=0;
    for(auto it:v){
        if(it%2) odd.push_back(it);
        else even.push_back(it);
    }
    for(int i=0;i<odd.size();i+=2){
        if(i==odd.size()-1){
            int x=mx-odd[i];
            if(x%2){
                return -1;
            }
            ans+=x/2;
            break;
        }
        ans+=(odd[i+1]-odd[i])/2;
        ans+= mx-odd[i+1];
    }
    for(int i=0;i<even.size();i+=2){
        if(i==even.size()-1){
            int x=mx-even[i];
            if(x%2){
                return -1;
            }
            ans+=x/2;
            break;
        }
        ans+=(even[i+1]-even[i])/2;
        ans+= mx-even[i+1];
    }
    return ans;
}


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v){
        cin>>it;
    }
    sort(v.begin(),v.end());
    ll one=recur(n,v,v[n-1]);
    ll two=recur(n,v,v[n-1]+1);
    if(one==-1 and two==-1){
        cout<<-1<<endl;
        return;
    }
    if(one!=-1 and two!=-1){
        cout<<min(one,two)<<endl;
        return;
    }
    cout<<max(one,two)<<endl;
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






   
