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




//product of the individual digits should be divisible by P
//count the number of such integers in the range [L,R]

//pos lead flag tight
// ll dp[12][12][2][2];
map<ll,map<ll,map<ll,map<ll,map<ll,ll>>>>> dp;
string L,R;
ll P;

ll recur(ll pos,bool lead,ll modLeft,bool flag,bool tight,string &s){
    if(pos>=s.length()){
        if(!lead && flag) return 1;
        return 0;
    }
    if(dp[pos][lead][flag][modLeft].count(tight)) 
        return dp[pos][lead][flag][modLeft][tight];

    ll ans=0;
    ll limit=((tight)?(s[pos]-'0'):9);

    for(ll dig=0;dig<=limit;++dig){
        if(lead && dig==0){
            ans+=recur(pos+1,1,modLeft,0,tight&(dig==limit),s);
        }
        else{
            if(modLeft==P)modLeft=1;
            ll pro=modLeft*dig;
            ll newMod=pro%P;
            ans+=recur(pos+1,0,newMod,flag|(newMod==0),tight&(dig==limit),s);
        }
    }
    return dp[pos][lead][flag][modLeft][tight]=ans;
}

bool printprimefactors(ll n){
    if(n<=1) return 1;
    while(n%2==0){
        n=n/2;
    }
     while(n%3==0){
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6){
        while (n%i==0){
            if(i>7) return 0;
            n=n/i;
        }
        while(n%(i+2)==0){
            if(i>7) return 0;
            n=n/(i+2);
        }
    }
    if(n>3) return 0;
    return 1;
}

void solve(){
    dp.clear();
    cin>>L>>R>>P;
    if(!printprimefactors(P)){
        cout<<0<<endl;
        return;
    }
    for(ll x=L.length()-1;x>=0;--x){
        if(L[x]!='0'){
            L[x]--;
            break;
        }else{
            L[x]='9';
        }
    }

    ll fr=recur(0,1,P,0,1,R);
    ll fl=recur(0,1,P,0,1,L);

    ll ans=(fr-fl);
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

