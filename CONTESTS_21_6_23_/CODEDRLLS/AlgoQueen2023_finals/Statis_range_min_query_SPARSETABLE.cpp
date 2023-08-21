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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */


// https://cp-algorithms.com/sequences/rmq.html


//method 1 : sparse table
//preprocessing -> O(NlogN)
//query         -> ?
//tc = O(NlogN + Q)


// sparse tables can be used for:
//min max gcd 
//but NOT for sum


class SparseTable{
    public:
    vector<vector<int>> vec;

    SparseTable(int n,int m,vector<int> &v){
        vec.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;++i){
            vec[i][0]=v[i];
        }
        
    }
    void preProcess(){
        int n = vec.size();
        int m = log2(n)+1;
        for(int i=1;i<m;i++){
            for(int j=0;j+(1<<i)<n;j++){
                vec[j][i] = min(vec[j][i-1],vec[j+(1<<(i-1))][i-1]);
            }
        }
    }
    int query(int L,int R){
        int len=R-L+1;
        int j = log2(len);
        return min(vec[L][j],vec[R-(1<<j)+1][j]);
    }

};

void solve() {
	int n,q;
    cin>>n>>q;
    vector<int> v(n);
    inpv(v);
    vector<pair<int,int>> queries(q);

    SparseTable st=SparseTable(n,log2(n)+1,v);
    st.preProcess();
    fr(i,q){
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<st.query(l,r)<<endl;
    }

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






   
