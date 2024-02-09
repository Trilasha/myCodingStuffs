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
    ll n,x;
    cin>>n>>x;
    if(x==0){
        fr(i,n){
            cout<<i+1<<" ";
        }
        cout<<endl;
        return;
    }
    if(n==1 || (x>=(n-1))){
        cout<<-1<<endl;
        return;
    }
    if(x==n-2){
        cout<<n<<" ";
        for(ll i=1;i<n;++i){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    ll fill=(n-1-x);
    if(fill==2){
        cout<<1<<" "<<n<<" ";
        for(ll i=2;i<n;++i){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    vector<ll> ans(n+1);
    ans[n]=n;
    ans[1]=1;
    fill--;
    ans[fill]=n-1;
    ll curr=2;
    for(ll i=1;i<=n;++i){
        if(ans[i]==0){
            ans[i]=curr;
            curr++;
        }
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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

