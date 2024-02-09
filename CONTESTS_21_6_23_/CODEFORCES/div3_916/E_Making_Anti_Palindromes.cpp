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
    string s;
    cin>>s;
    if(n%2){
        cout<<-1<<endl;
        return;
    }
    vector<ll> v(26);
    for(ll i=0;i<n;++i){
        v[s[i]-'a']++;
    }
    for(ll i=0;i<n/2;++i){
        if(s[i]!=s[n-i-1]){
            v[s[i]-'a']--;
            v[s[n-i-1]-'a']--;
        }
    }
    for(ll i=0;i<26;++i){
        v[i]/=2;
    }
    ll mx=*max_element(all(v));
    ll sum=accumulate(all(v),0LL);
    if(mx<=(sum-mx)){
        if(sum%2==0){
            cout<<sum/2<<endl;
        }
        else{
            cout<<sum/2+1<<endl;
        }
    }else{
        ll diff=mx-(sum-mx);
        ll ans=(sum-mx);
        char ch='a';
        for(ll i=0;i<26;++i){
            if(v[i]==mx){
                ch=i+'a';
                break;
            }
        }
        //cout<<ch<<" "<<diff<<" "<<ans<<endl;
        for(ll i=0;i<n/2;++i){
            if(diff==0)break;
            if(s[i]!=ch && s[n-i-1]!=ch && s[i]!=s[n-i-1]){
                diff--;
                ans++;
            }
        }
        cout<<((diff==0)?ans:-1)<<endl;
    }

 
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

