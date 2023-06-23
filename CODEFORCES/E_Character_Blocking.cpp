#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///






//padhlena tha...missed!!
void solve(){
    string s1,s2;
    cin>>s1>>s2;

    ll t, que;
    cin>>t>>que;

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    set<ll> not_match;


    for(ll i=0;i<s1.size();++i){
        if(s1[i]!=s2[i]){
            not_match.insert(i);
        }
    }

    //debugset(not_match);

    for(ll i=0;i<que;++i){
        ll type;
        cin>>type;

        if(!pq.empty() && (i-pq.top().ff)>=t){
            //line
            ll ind=pq.top().ss;
            if(s1[ind]!=s2[ind]){
                not_match.insert(ind);
            }
            pq.pop();
        }

        if(type==1){
            ll ind;
            cin>>ind;
            ind--;
            pq.push({i,ind});
            if(not_match.size()>0 && not_match.find(ind)!=not_match.end()){
                not_match.erase(ind);
            }

        }else if(type==2){
            ll no,pos,noo,poss;
            cin>>no>>pos>>noo>>poss;
            //
            if(no==1 && noo==1){
                swap(s1[pos-1],s1[poss-1]);
            }
            else if(no==1 && noo==2){
                swap(s1[pos-1],s2[poss-1]);
            }else if(no==2 && noo==1){
                swap(s2[pos-1],s1[poss-1]);
            }else{
                swap(s2[pos-1],s2[poss-1]);
            }
            if(s1[pos-1]==s2[pos-1] && not_match.find(pos-1)!=not_match.end()){
                    not_match.erase(pos-1);
            }else if(s1[pos-1]!=s2[pos-1]){
                    not_match.insert(pos-1);
            }
            if(s1[poss-1]==s2[poss-1] && not_match.find(poss-1)!=not_match.end()){
                    not_match.erase(poss-1);
            }else if(s1[poss-1]!=s2[poss-1]){
                    not_match.insert(poss-1);
            }
            
        }else{
            if(not_match.empty()){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }

       
    }
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}