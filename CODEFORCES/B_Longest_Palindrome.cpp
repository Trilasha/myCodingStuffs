/*
Trilasha Mazumder
2112063
*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


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
#define maxval                1000000007
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
void google(ll t) {cout << "Case #" << t << ": ";}


void avoid_error()
{
/*
when the ans vector contains modulated values,then take the modulo(%) while calculating the elements' value...DON'T JUST PUT % AT THE TIME OF INSERTION 
CORRECT                     :-loop-->anss=(anss*powers[j])%(nn); then ans.pb(anss);
WRONG(tle,rte or wa)        :-loop-->anss=(anss*powers[j]); then ans.pb(anss%nn);
AVOID creating any prefix product array in case of modulo problems

-->take size +1(atleast extra) for vectors to avoid out of bounds

-->ll suma=accumulate(all(a),0LL);
//put OLL or else WA for larger sum
*/
}


    
bool Is_Palindrome(string s){
   ll n = s.size();
  fr(i,n/2)
{
    if(s[i] != s[n-i-1]){
         return false;
      }
}
   return true;
}

void solve()
{
   inp(num);
   inp(len);

   map<char,ll> mp;
   map<string,ll> mp2;
 
   vector<string> v;
   for(ll i=0;i<num;++i)
   {
    string s;
    cin>>s;
    v.pb(s);
    mp2[s]++;
   }

    for(ll i=0;i<v.size();++i)
   {
    for(auto &j:v[i])
    mp[j]++;
   }

  //printmap(mp2);

   ll chk=0;
   string ans="";
   string ansl="";
   string ansr="";
   string temp="";
     string sp="";

   for(ll i=0;i<v.size();++i)
   {
    temp=v[i];
    reverse(all(temp));
    //cout<<temp<<endl;

    if(mp2.find(temp)!=mp2.end())
    {
        if(temp!=v[i] && mp2[temp]!=0)
        {
        ans+=v[i];
        ans+=temp;
        ansl+=v[i];
        ansr+=temp;
        mp2[temp]--;
        mp2[v[i]]--;
        }
        else if(temp==v[i] && mp2[temp]==1 && Is_Palindrome(temp)==1 && chk==0)
        {
            sp+=temp;
            chk=1;
            mp2[temp]--;
        }
       //cout<<ans<<endl;
    }
    else if(mp2.find(temp)==mp2.end() && mp2[v[i]]==1)
    {
       if(mp[v[i][0]]==v[i].size() && chk==0 && Is_Palindrome(v[i])==1)
       {
        ans+=v[i];
        sp+=v[i];
        mp2[v[i]]--;
        chk=1;
       }

    }
   }
//cout<<ansl<<endl;
string tt=ansl;
  reverse(all(ansl));
  //cout<<sp<<endl;
 cout<<ansl.size()*2+sp.size()<<endl;
  cout<<ansl<<sp<<tt<<endl;

   //cout<<ans<<endl;
       
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















