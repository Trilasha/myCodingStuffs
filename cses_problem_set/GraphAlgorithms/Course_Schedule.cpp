/* ...  risen_ash  ... */

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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




vector<int> findOrder(int N, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adjList(N+1);
	    for(auto &i:prerequisites){
	        adjList[i[0]].push_back(i[1]);
        }
	    
	    //using toposort bfs to detect the presence of a cycle
	    vector<int> indegree(N+1,0);
	    for(auto &i:adjList){
	        for(auto &j:i)
	        indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=1;i<=N;++i){
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &i:adjList[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    
	    if(topo.size()==N)
	    return topo;
	    else
	    return {};
    }

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> prerequisites(m,vector<int>(2));
    fr(i,m){
        cin>>prerequisites[i][0]>>prerequisites[i][1];
    }
   
    vector<int> ans=findOrder(n,prerequisites);
    if(!ans.size()){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    printv(ans);
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */