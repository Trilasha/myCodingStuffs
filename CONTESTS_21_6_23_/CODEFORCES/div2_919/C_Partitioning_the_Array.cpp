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
// #define md                    998244353
#define md               1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */





// vector<ll> hash1,power1,invMod1;
 
// ll radix=31;
// ll mod=1e9+7;
 
// ll expo(ll b,ll e,ll md){
//     ll ans=1;
//     while(e){
//         if(e&1) ans=(ans*b)%md;
//         b=(b*b)%md;
//         e/=2;
//     }
//     return ans;
// }
// void precal(string &s){
//     ll n=s.size();
//     hash1.assign(n+5,1LL);
//     ll a=1;
//     for(ll x=0;x<n;++x){
//         hash1[x+1]=(hash1[x]+(s[x]-'a'+1)*a)%mod;
//         a=(a*radix)%mod;
//     }
// }
 
// ll invmod(ll p){
//     return expo(p,mod-2,mod);
// }
// void preInv(){
//     power1.assign(1e6+10,1LL);
//     invMod1.assign(1e6+10,1LL);
//     for(ll i=1;i<=1e6+1;i++){
//         power1[i]=(power1[i-1]*radix)%mod;
//         invMod1[i]=invmod(power1[i]);
//     }
// }
 
// ll calc(ll left,ll right){
//     ll val=(hash1[right]-hash1[left-1]+mod)%mod;
//     ll ans=(val*invMod1[left-1])%mod;
//     return ans;
// }
 
 
ll expo(ll b, ll e){
     ll ret=1;
     for(;e;e/=2,b=(b*b)%md){
          if(e&1) ret=(ret*b)%md;
     }
     return ret;
}
ll inv(ll x){
     return expo(x,md-2);
}
 
vector<ll>cInv,cPow;
 
void calc(){
    cPow.assign(1e6+10,1LL);
    cInv.assign(1e6+10,1LL);
     for(int i=1;i<=1e6+1;i++){
          cPow[i]=(cPow[i-1]*31)%md;
          cInv[i]=inv(cPow[i]);
     }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    string s;
    cin>>s;
    ll ans=0;
    for(auto &i:v){
        if(i%2)s+='1';
        else s+='0';
    }
    // preInv();
    // precal(s);


    // cout<<s<<endl;
    // cout<<calc(1,2)<<" "<<calc(3,2)<<endl;

     calc();
     vector<ll>hash(n+1,0LL);
     const ll P=31;
     ll mul=1;
     for(ll i=0;i<n;i++){
          hash[i+1]=(hash[i]+(s[i]-'a'+1)*mul)%md;
          mul=(mul*P)%md;
     }
 
     auto get_hash=[&](ll l,ll r){
          ll ret=(hash[r]-hash[l-1]+md)%md;
          ret=(ret*cInv[l-1])%md;
          return ret;
     };

    for(ll i=0;i<n;++i){
        if(n%(i+1)==0){
            ll div=n/(i+1);
            ll x=get_hash(1,i+1);
            ll y=get_hash(1,n);
            cout<<i+1<<" "<<x<<" "<<y<<" "<<div<<endl;
            if(div==1){
                ans++;
                continue;
            }
            if((x*(div))%md==y){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

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

