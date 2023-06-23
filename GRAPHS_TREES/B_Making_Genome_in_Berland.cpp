/*
Trilasha Mazumder
2112063
*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
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
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
ll expo(ll a, ll b, ll modd) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % modd; a = (a * a) % modd; b = b >> 1;} return res;}

/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t)             {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///








vector<int> toposort(vector<vector<int>> &newAdj,int K)
    {
        vector<int> indegree(K,0);
        vector<int> topo;
	    for(auto &i:newAdj)
	    {
	        for(auto &j:i)
	        indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<K;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	
	
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &i:newAdj[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    return topo;
} 

void dfs(ll curr,vector<vector<int>> &newAdj,vector<ll> &vis,string &ans)
{
    vis[curr]=0;
    ans+=(curr+'a');
    for(auto &i:newAdj[curr])
    {
        if(vis[i])
        dfs(i,newAdj,vis,ans);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    vector<ll> vis(26,0);
 
    vector<vector<int>> newAdj(26);
		int chk=0;
        for(int i=0;i<n;++i)
        {
            string s=v[i];


            for(int j=0;j<s.size()-1;++j)
            {
                char one=s[j];
                char two=s[j+1];
                newAdj[one-'a'].pb(two-'a');
                vis[s[j]-'a']=1;  
            }

            vis[s[s.size()-1]-'a']=1;
        }

        // for(int i=0;i<26;++i)
        // {
        //     cout<<char(i+'a')<<"-->";
        //     printv(newAdj[i]);
        // }

        vector<int> topo=toposort(newAdj,26);

       // printv(topo);
	    string ans="";
	   
        for(auto &i:topo)
        {
            if(vis[i])
                dfs(i,newAdj,vis,ans);
        }
	    cout<<ans<<endl;
    

}


int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}
















