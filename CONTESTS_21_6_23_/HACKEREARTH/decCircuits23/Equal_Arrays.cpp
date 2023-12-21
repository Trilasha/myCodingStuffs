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
   ll n,m;
   cin>>n>>m;
   vector<ll> a(n),b(m);
   inpv(a);inpv(b);
   ll cnt=0;
   ll suma=a.back(),sumb=b.back();
   ll i=n-1,j=m-1;
   while(i>=0 || j>=0){
       if(suma>sumb){
            if((j-1)>=0){
                j--;
                sumb+=b[j];
            }else break;
       }else if(suma<sumb){
            if((i-1)>=0){
                i--;
                suma+=a[i];
            }else break;
       }
       if(suma==sumb){
            cnt++;
            i--;
            j--;
            suma=0;
            sumb=0;
            if(i>=0)suma+=a[i];
            if(j>=0)sumb+=b[j];
       }
   }
   cout<<((!suma && !sumb)?cnt:-1)<<endl;
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

