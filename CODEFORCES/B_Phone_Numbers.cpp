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
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
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
///vector<vector<int>> M;
//M.resize(m, vector<int>(n));
//binary_search(all(v),5)-->returns boolean value
// iota(all(v),10); -- > o/p--> 10 11 12 13 14 15 16 17 18 19
// a + b = a ^ b + 2 * (a & b)
///------------------------------------------------------------------------------------------------///



bool cmp(pair<pair<string,ll>,ll> &a,pair<pair<string,ll>,ll> &b)
{
    if(a.ff.ss==b.ff.ss)
    return a.ss<b.ss;

    else
    return a.ff.ss>=b.ff.ss;
}


void solve()
{
  ll n;
  cin>>n;

  map<string,ll> taxi,pizza,girls;
  map<string,ll> mp;


  for(ll i=0;i<n;++i)  
  {
    ll n;
    cin>>n;

    string s;
    cin>>s;

    mp[s]=i;

    if(n==0)
    {
        taxi[s]=0;
        pizza[s]=0;
        girls[s]=0;
    }


    for(ll j=0;j<n;++j)
    {

        string tt;
        cin>>tt;
        string temp="";
        fr(i,tt.size())
        {
            if(tt[i]!='-')
            temp+=tt[i];
        }


        set<char> st;
        fr(i,temp.size())
        st.insert(temp[i]);

        if(st.size()==1)
        taxi[s]++;
        else 
        {
            ll chk=0;
            for(ll i=1;i<temp.size();++i)
            {
                if(temp[i]>=temp[i-1])
                {
                    chk=1;
                    break;
                }
            }             
            
            if(chk==0)                                                                                                                                                                                                                                                                                                                                                           
            pizza[s]++;
            else
            girls[s]++;
        }
    }

    if(taxi.count(s)==0)
    taxi[s]=0;

    if(pizza.count(s)==0)
    pizza[s]=0;
    
    if(girls.count(s)==0)
    girls[s]=0;
  }




  vector<pair<pair<string,ll>,ll>> t,p,g;
  for(auto &i:taxi)
  t.pb({{i.ff,i.ss},mp[i.ff]});

  for(auto &i:pizza)
  p.pb({{i.ff,i.ss},mp[i.ff]});


  for(auto &i:girls)
  g.pb({{i.ff,i.ss},mp[i.ff]});

  sort(all(t),cmp);
  sort(all(p),cmp);
  sort(all(g),cmp);



  ll mx_taxi=t[0].ff.ss;
  ll mx_pizza=p[0].ff.ss;
  ll mx_girls=g[0].ff.ss;

  ll ind=0;

  cout<<"If you want to call a taxi, you should call:";
  for(ll i=0;i<t.size();++i)
  {
    if(t[i].ff.ss==mx_taxi)
    {
       ind=i;
    }
  }
  
  for(ll i=0;i<t.size();++i)
  {
    if(i==ind)
    {
        cout<<" "<<t[i].ff.ff<<"."<<endl;
        break;
    }
    if(t[i].ff.ss==mx_taxi)
    {
       cout<<" "<<t[i].ff.ff<<",";
    }
  }
  

  //
   cout<<"If you want to order a pizza, you should call:";
  for(ll i=0;i<p.size();++i)
  {
    if(p[i].ff.ss==mx_pizza)
    {
       ind=i;
    }
  }
  
  for(ll i=0;i<p.size();++i)
  {
    if(i==ind)
    {
        cout<<" "<<p[i].ff.ff<<"."<<endl;
        break;
    }
    if(p[i].ff.ss==mx_pizza)
    {
       cout<<" "<<p[i].ff.ff<<",";
    }
  }


  //
   cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
  for(ll i=0;i<g.size();++i)
  {
    if(g[i].ff.ss==mx_girls)
    {
       ind=i;
    }
  }
  
  for(ll i=0;i<g.size();++i)
  {
    if(i==ind)
    {
        cout<<" "<<g[i].ff.ff<<"."<<endl;
        break;
    }
    if(g[i].ff.ss==mx_girls)
    {
       cout<<" "<<g[i].ff.ff<<",";
    }
  }
  




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


































