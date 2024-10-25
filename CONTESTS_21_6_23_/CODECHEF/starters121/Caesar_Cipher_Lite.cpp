/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<ll> ans;
    for(ll i=0;i<n;++i){
        if(a[i]==b[i]){
            ans.pb(0);
        }else{
            ll val1=(a[i]-'A'+1);
            ll val2=(b[i]-'A'+1);
            ll r1=(a[i]-'A'+1)%3;
            ll r2=(b[i]-'A'+1)%3;
            ll cnt=0;
            if(r1==r2){
                if(val1<val2){
                    ans.pb((val2-val1)/3);
                }else{
                    ll cnt=0;
                    if(r1==1){
                        cnt+=(val2-1)/3;
                        cnt+=(25-val1)/3;
                        cnt+=18;
                    }else if(r1==2){
                        cnt+=(val2-2)/3;
                        cnt+=(26-val1)/3;
                        cnt+=18;
                    }else{
                        cnt+=(val2-3)/3;
                        cnt+=(24-val1)/3;
                        cnt+=19;
                    }
                    ans.pb(cnt);    
                }
            }else{
                while(r1!=r2){
                    if(r1==1){
                        cnt+=25-val1;
                        cnt+=3;
                        val1=2;
                        r1=2;
                    }else if(r1==2){
                        cnt+=26-val1;
                        cnt+=3;
                        val1=3;
                        r1=0;
                    }else{
                        cnt+=24-val1;
                        cnt+=3;
                        val1=1;
                        r1=1;
                    }
                }
                ll mx=max(val1,val2);
                ll mn=min(val1,val2);
                cnt+=mx-mn;
                ans.pb(cnt/3);
            }
        }
    }
    printv(ans);
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

