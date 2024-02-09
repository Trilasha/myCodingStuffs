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




//initial code (issue was only with the string formation in NO case)
void solve(){
    ll n,k,len;
    cin>>n>>k>>len;
    string s;
    cin>>s;

    ///
    map<ll,set<ll>> mp;
    for(ll i=0;i<len;++i){
        mp[s[i]-'a'].insert(i);
    }
    // if(k==1){
    //     if(mp[0].size()<n){
    //         cout<<"NO"<<endl;
    //         for(ll i=0;i<n;++i){
    //             cout<<'a';
    //         }
    //         cout<<endl;
    //         return;
    //     }else{
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    //     return;
    // }
    // if(n==1){
    //     for(char ch='a';ch<char('a'+k);++ch){
    //         if(mp[ch-'a'].size()==0){
    //             cout<<"NO"<<endl;
    //             cout<<ch<<endl;
    //             return;
    //         }
    //     }
    //     cout<<"YES"<<endl;
    //     return;
    // }
    ll ori=k;
    for(char ch='a';ch<char('a'+k);++ch){
        // if(ori==0)break;
        if(mp[ch-'a'].size()<n){
            cout<<"NO"<<endl;
            for(ll i=0;i<n;++i){
                cout<<ch;
            }
            cout<<endl;
            return;
        }
        // ori--;
    }
    ////////////

    ll cnt=0;
    ll last=0;
    ll req=(1LL<<k);
    string ans="";
    for(ll i=0;i<len;++i){
        ll mask=0;
        ll j=i;
        while(j<len){
            ll ch=s[j]-'a';
            mask|=(1LL<<ch);
            j++;
            if(mask==(req-1)){
                ans+=s[j-1];
                cnt++;
                break;
            }
        }
        if(j==len)break;
        last=mask;
        i=j-1;
    }
    // cout<<req<<" "<<cnt<<endl;
    if(cnt>=n){
        cout<<"YES"<<endl;
        return;
    }
    for(ll i=0;i<k;++i){
        if(ans.size()==n)break;
        if((last&(1LL<<i))==0){
           while(ans.size()<n){
               ans+=char('a'+i);
           }
           break;
        }
    }
    cout<<"NO"<<endl;
    cout<<ans<<endl;
    // line
 
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

