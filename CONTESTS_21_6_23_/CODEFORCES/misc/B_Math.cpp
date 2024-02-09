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
    ll ans=1;
    ll cnt=0;
    map<ll,ll> mp;
    if(n==1){
        cout<<1<<" "<<0<<endl;
        return;
    }
    while(n%2==0){
        mp[2]++;
        n/=2;
    }
    while(n%3==0){
        mp[3]++;
        n/=3;
    }
    for(ll i=5;i*i<=n;i+=6){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
        while(n%(i+2)==0){
            mp[i+2]++;
            n/=(i+2);
        }
    }
    if(n>3){
        mp[n]++;
    }
    ll ok=0;
    for(auto &i:mp){
        ans*=i.ff;
        cnt=max(cnt,i.ss);
    }
    if(!(cnt&(cnt-1))){
        for(auto &i:mp){
            if(i.ss!=cnt){
                ok=1;
                break;
            }
        }
        if(ok){
            cout<<ans<<" "<<log2(cnt)+1<<endl;
        }else{
            cout<<ans<<" "<<log2(cnt)<<endl;
        }
        return;
    }
    ll p=1;
    while(p<cnt){
        p*=2;
    }
    cout<<ans<<" "<<log2(p)+1<<endl;
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

