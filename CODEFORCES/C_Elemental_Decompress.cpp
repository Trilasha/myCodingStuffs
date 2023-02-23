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
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define mod                   1000000007
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
/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t) {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///
//  v[i]=pow(10,v[i])+0.1; 
//max 1e7 size vector can be created







bool cmp(pair<pair<ll,ll>,pair<ll,ll>> &a,pair<pair<ll,ll>,pair<ll,ll>> &b)
{
    return a.first.first<b.first.first;
}
void solve()
{
    inp(n);
    vector<ll> maxy(n);
    inpv(maxy);
    map<ll,ll> mp;

    fr(i,n)
    mp[maxy[i]]++;

    for(auto &ele:mp)
    {
        if(ele.second>2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    vector<ll> chk=maxy;
    sort(all(chk));

    fr(i,n)
    {
        if(chk[i]<(i+1))
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    set<ll> sp;
    set<ll> sq;
    vector<pair< pair<ll,ll>, pair<ll,ll> > > vp;
    vector<pair<ll,ll>> v;

    fr(i,n)
    v.pb({maxy[i],i+1});

    sort(all(v),greater<pair<ll,ll>>());


    vector<ll> p(n);
    vector<ll> q(n);

    fr(i,n)
    {
        if(sp.find(v[i].first)==sp.end())
        {
        p[i]=v[i].first;
        sp.insert(v[i].first);
        }
        else if(sq.find(v[i].first)==sq.end())
        {
        q[i]=v[i].first;
        sq.insert(v[i].first);
        }
    }

    vector<ll> rem_p;
    vector<ll> rem_q;

    for(ll i=1;i<=n;++i)
    {
        if(sp.find(i)==sp.end())
        rem_p.pb(i);
        if(sq.find(i)==sq.end())
        rem_q.pb(i);
    }

    fr(i,n)
    {
        if(p[i]==0)
        {
        p[i]=rem_p[rem_p.size()-1];
        rem_p.pop_back();
        }
        else
        {
        q[i]=rem_q[rem_q.size()-1];
        rem_q.pop_back();
        }
    }

    fr(i,n)
    {
        vp.pb({{v[i].second,v[i].first},{p[i],q[i]}});
    }

    sort(all(vp),cmp);

    vector<ll> ansp,ansq;

    fr(i,n)
    {
        ansp.pb(vp[i].second.first);
        ansq.pb(vp[i].second.second);
    }

    cout<<"YES"<<endl;
    printv(ansp);
    printv(ansq);


}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}


































