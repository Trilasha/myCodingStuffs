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





string findDiff(string str1, string str2) { 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i = 0; i < n2; i++) { 
    int sub = ((str1[i] - '0') - (str2[i] - '0') - carry); 
    if (sub < 0) { 
        sub = sub + 10; 
        carry = 1; 
    } 
    else
        carry = 0; 
    str.push_back(sub + '0'); 
    }
    for (int i = n2; i < n1; i++) { 
    int sub = ((str1[i] - '0') - carry); 
    if (sub < 0) { 
        sub = sub + 10; 
        carry = 1; 
    } 
    else
        carry = 0; 
    str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
    return str; 
} 



/*
number is d-magic if 
1)digit d appears on even positions and nowhere else.
2)multiple of m
d (1 ≤ m ≤ 2000, 0 ≤ d ≤ 9)
range digits cnt <=2000
*/ 

//pos lead num tight
ll dp[2010][2010][2];
ll d,m;
string L,R;

ll recur(ll pos,ll num,bool tight,string &s){
    if(pos>=s.length()){
        if(num==0) return 1;
        return 0;
    }
    if(dp[pos][num][tight]!=-1) 
        return dp[pos][num][tight];

    ll ans=0;
    ll limit=((tight)?(s[pos]-'0'):9);

    for(ll dig=0;dig<=limit;++dig){
        if(dig==d && pos%2){
            ans=(ans+recur(pos+1,(num*10+dig)%m,tight&(dig==limit),s))%modval;
        }else if(dig!=d && pos%2==0){
            ans=(ans+recur(pos+1,(num*10+dig)%m,tight&(dig==limit),s))%modval;
        }
    }
    return dp[pos][num][tight]=ans;
}

void solve(){
    cin>>m>>d;
    cin>>L>>R;
    //L=findDiff(L,"1");
    for(ll x=L.length()-1;x>=0;--x){
        if(L[x]!='0'){
            L[x]--;
            break;
        }else{
            L[x]='9';
        }
    }

    memset(dp,-1,sizeof(dp));
    ll fr=recur(0,0,1,R);
    memset(dp,-1,sizeof(dp));
    ll fl=recur(0,0,1,L);

    ll ans=(fr-fl+modval)%modval;
    cout<<ans<<endl;
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

