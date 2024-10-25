/*
    Trilasha Mazumder
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
    ll n,m,s;
    cin>>n>>m>>s;
    set<ll> st,temp;
    st.insert(s);
    for(ll i=0;i<m;++i){
        ll val;char ch;
        cin>>val>>ch;
        if(ch=='0'){
            set<ll> temp;
            for(auto &i:st){
               ll rem=(i+val)%n;
               if(rem==0)rem=n;
               temp.insert(rem);
            }
            swap(temp,st);
        }else if(ch=='1'){
            set<ll> temp;
            for(auto &i:st){
               ll rem=(i-val+n)%n;
               if(rem==0)rem=n;
               temp.insert(rem);
            }
            swap(temp,st);
        }else{
            set<ll> temp;
            for(auto &i:st){
               ll rem=(i+val)%n;
               if(rem==0)rem=n;
               temp.insert(rem);
               rem=(i-val+n)%n;
               if(rem==0)rem=n;
               temp.insert(rem);
            }
            swap(temp,st);
        }
    }
    cout<<st.size()<<endl;
    for(auto &i:st){
        cout<<i<<" ";
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

