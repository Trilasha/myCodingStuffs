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



bool LC(char &ch){
    return (ch>='a' && ch<='z');
}
bool UC(char &ch){
    return (ch>='A' && ch<='Z');
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll qq;
    cin>>qq;
    map<char,ll> up,low;
    map<char,set<ll>> stlow,stup;
    for(ll i=0;i<n;++i){
        if(LC(s[i])) low[s[i]]++;
        else up[s[i]]++;
    }

    for(ll i=0;i<qq;++i){
        ll type,x;
        char ch;
        cin>>type>>x>>ch;
        x--;
        if(type==1){
            s[x]=ch;
            if(LC(s[x])){
                low[s[x]]++;
                if(stup.find(x)!=stup.end()){
                    stup.erase(x);
                }
                stlow[s[x]].insert(x);
            }
            else{
                up[s[x]]++;
                if(stlow.find(x)!=stlow.end()){
                    stlow.erase(x);
                }
                stup[s[x]].insert(x);
            }
        }else if(type==2){
            for(char ch='a';ch<='z';++ch){
                if(up[toupper(ch)]>0){
                    low[ch]++;
                    up[toupper(ch)]--;
                }
            }
        }else{
            for(char ch='A';ch<='Z';++ch){
                if(low[tolower(ch)]>0){
                    up[ch]++;
                    low[tolower(ch)]--;
                }
            }
        }
        //cout<<s<<endl;
    }
    string ans="";
    for(ll i=0;i<n;++i){
        if(LC(s[i])){
            if(low[s[i]]>0){
                char ch=tolower(s[i]);
                if(stlow[ch].find(i)!=stlow[ch].end()){
                    stlow[ch].erase(i);
                }
                ans+=tolower(s[i]);
            }else{
                ans+=toupper(s[i]);
            }
        }else{
            if(up[s[i]]>0){
                char ch=toupper(s[i]);
                if(stup[ch].find(i)!=stup[ch].end()){
                    stup[ch].erase(i);
                }
                ans+=toupper(s[i]);
            }else{
                ans+=tolower(s[i]);
            }
        }
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   
