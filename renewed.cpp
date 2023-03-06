/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///


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
-->### when the input is a number then take the input as a STRING  ###
-->### when size>=1e9, go with maps(no size contraints) instead of vect of vect
//(ll)ceil(double(n)/2)
//declare the adj,vis,v globally in case of graphs/trees question
*/
}


















//********************************************************* SOME VECTOR HACKS ***********************************************
//vector<vector<ll>> v(n, vector<ll> (m,0));
//ll ans1 = accumulate(ans.begin(), ans.end(), 0LL);  



//******************** how to insert in a pair ******************************************************************************
/*
pair<char, int> pair1 = make_pair('A', 1);
or
pair<int,int> p;
p.first=1;
p.second=2;
vector<pair<ll,ll>> vp;
vp.pb({a[i],b[i]});
*/
//###########################################################################################################################
/*
ll c=count(str.begin(),str.end(),'0');
*/


//########################################## IMPORTANT NOTES FOR UB AND LB ##################################################
/*
v.end()-v.begin() == vector/array size
in the other cases it will return the index number
--> if wanted in 1-based index then upper_bound(v.begin(),v.end(),val)-v.begin()+1;
--> if wanted in 0-based index then upper_bound(v.begin(),v.end(),val)-v.begin();
*/

//#################################### POINTS TO BE NOTED #######################################################################
/*
-->when max value is to be found,always initialize it with the smallest value possible like 0 or -1
-->when min value is to be found,always initialize it with the highest value possible like n(size of the array/vector) or INT_MAX
-->when the value of index is to be stored or updated in a loop,initialize it with -1
--> ceil of a/b = (a+b-1)/b floor is (a-1)/b
-----------------------------------------------------------------
---  //cout<<(ll)ceil((double)(ceil((double)n/k)*k)/n)<<endl; ---
---  // cout<<(((n+k-1)/k*k)+n-1)/n<<endl;                    ---
---  BOTH ARE SAME                                            ---
-----------------------------------------------------------------
-->string str;
   getline(cin,str);
//to take a string with spaces as an input
//###############################################################################################################################
*/

//deque<char> d;

// ll x= log10(n);
// ll y= pow(10, x)+ 0.005;
//not understood the 0.005 part

//###############################################################################################################################
/*
 for (int i=0;i<=n;i++) mp[i]++; 
    for (int i=0; i<n; i++) {
        mp.erase(arr[i]); 
    }
    cout << mp.begin()->first << endl; 
*/


//###############################################################################################################################
/*
vector<bool> vis(n+1,false);
*/

//#################################################  USE OF BITSET ##############################################################################
/*
for(ll i=0;i<n;i++){
      cin>>arr[i];
      sum=sum+arr[i];
    }
    bitset<64>b(sum);
    cout<<b.count()<<endl;
*/

//#################################################TO SORT A MAP BY VALUES ##############################################################################
//multimaps can store duplicate keys also
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  multimap<ll,ll> mm;
//         for(auto &i:mp)
//         {
//             mm.insert({i.second,i.first});
//         }
///////   

/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                  1000000007
#define PI          3.141592653589793238
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)              ll n;cin>>n;
#define inpv(v)              for(auto &x: v) cin>>x;
#define make(arr,n)   ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
/// ------------------------------------FUNCTIONS 1.0---------------------------------------- ///
//way1
ll countDigit(ll n)
{
   if(n == 0)
     return 1;
    ll count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}
//way2
ll countDigit(ll n) {
  return floor(log10(n) + 1);
}


//
 int reverse(int n){
        int a = 0;
        while(n>0){
            a*=10;
            a+=n%10;
            n/=10;
        }
        return a;
    }
    //reverse of 100 will be 1(not 001)

/////// less than root(n)
bool isPrime(ll n)
{
 if(n==1) return false;
if(n==2 || n==3) return true;
if(n%2==0 || n%3==0) return false;
for(ll i=5;i*i<=n;i=i+6)
if(n%i==0 || n%(i+2)==0)
return false;
return true;
}

///////
void divisors(ll n)
{
for (ll i = 1; i*i <=n; i++)
{
if(n%i==0)
{
cout<<i<<" ";
if(i!=n/i)
cout<<n/i<<" ";
}
}
}

///////
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

///////
void printprimefactors(ll n)
{
    if(n<=1) return;
    while(n%2==0)
    {
        cout<<2;
        n=n/2;
    }
     while(n%3==0)
    {
        cout<<3;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
            cout<<i;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2;
            n=n/(i+2);
        }
    }
    if(n>3)
    cout<<n;
    return;
    //i/p-->450
    //o/p-->23355
}
//tc-theta(sqrt(n))

///////
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

///////
ll binarysearch(ll arr[],ll n,ll key)
{
    ll lo=0,hi=n-1;
    ll mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]<key)
        lo=mid+1;
        else if(arr[mid]>key)
        hi=mid-1;
        else
        return mid;
    }
    return -1;
}

///////
ll ternary_search(ll l,ll r,ll x,ll ar[])
{
    if(r>=l)
    {
        ll mid1 = l + (r-l)/3;
        ll mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x,ar);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x,ar);
        else
            return ternary_search(mid1+1,mid2-1,x,ar);

    }
    return -1;
}
///////
//TC--> nloglogn
void sieve(ll n){
 vector<bool> isprime(n+1,true);
    for (ll i = 2; i*i<=n; ++i)
    {
      if(isprime[i])
      {
        for (ll j = i*i; j<=n; j=j+i)
        {
           isprime[j]=false;
        }
      }
        
    }
    for (ll i = 2; i <=n; ++i)
    {
      if(isprime[i])
      cout<<i<<" ";
    }
    
}
ll MEX(vector<ll>&v){
   ll n  = v.size();
   map<ll, ll>m;
   for(int i = 0; i <= n; ++i){
      m[i]++;
   }
   for(int i = 0; i < n; ++i){
      m.erase(v[i]);
   }
   return m.begin()->first;
}

//
//if s1 is a subsequence of s2
bool issubsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}
bool issubsequence(string& t, string& s,ll tn,ll sn)
{
    if(tn==0)return 1;
    if(sn==0)return 0;
    if(t[tn-1]==s[sn-1])
    return issubsequence(t,s,tn-1,sn-1);
    else
    return issubsequence(t,s,tn,sn-1);
}

//in O(n) time complexity and O(1) constant extra space
bool isAnagram(string a,string b)
{
 
  if (a.length() != b.length()) {
    return false;
  }
  unordered_map<char,int> Map;
  for (ll i = 0; i < a.length(); i++) {
    Map[a[i]]++;
  }
  for (ll i = 0; i < b.length(); i++) {
    if (Map.find(b[i]) != Map.end()) {
      Map[b[i]] -= 1;
    } else {
      return false;
    }
  }
  for (auto items : Map) {
    if (items.second != 0) {
      return false;
    }
  }
  return true;
}

//###########################################     KADANE'S ALGORITHM      #####################################################
ll maximum_subarray_sum(vector<ll> &v)
{
    ll ans=0;
    ll var=INT_MIN;
    fr(i,v.size())
    {
        var=max(v[i],var+v[i]);
        ans=max(ans,var);
    }
    return ans;
}

//
//Note--->the array must be sorted in ascending order
  while(i<j)
    {
        if(diff[i]+diff[j]>=0)
        {
            i++;
            j--;
            ct++;
        }
        else
        {
            i++;
        }
    }



 for (ll i=1; i<100000; i++) {
        ll x = i * i * i; 
        if (x > 1e12) {
            break;
        }
        cube_roots.push_back(x);
    }


//to achieve the "sum" using "chance" number of positions
//https://codeforces.com/problemset/problem/476/B
double canrep(int sum, int chance) {
	if((sum - chance) % 2 != 0 || abs(sum) > chance){
		return 0;
	}
	sum = abs(sum);
	int p = (chance + sum) / 2;
	int n = (chance - sum) / 2;
	double ans = factorial(p+n);
	ans /= factorial(p);
	ans /= factorial(n);
	return ans;
}

/*//////////////////////////////////////////////////  TAKING PREFIX SUM   /////////////////////////////////////////////////////
ll pf[n];
    for (ll i = 0; i < n; i++)
    {
        pf[i]=0;
    }
    pf[0]=arr[0];
    for (ll i = 1; i < n; i++)
    {
        pf[i]=pf[i-1]+arr[i];
    }
    ///////////// PREFIX SUM AND SUFFIX SUM WAYS /////////////////
      vector<ll> pref(n+1),suff(n+1);
    for(ll i=1;i<=n;++i)
    {
        pref[i]=pref[i-1]+v[i-1];
    }
    for(ll i=n-1;i>=0;--i)
    {
        suff[i]=suff[i+1]+v[i];
    }
    //////////// HOW TO MAKE MINIMUM ARRAY OR VECTOR /////////////
     vector<ll> minarr(n+1);
    minarr[0]=v[0];
    for(ll i=1;i<n;++i)
    {
        minarr[i]=min(minarr[i-1],v[i]);
    }
*/

/*
///////////////////////////////   HOW TO STORE PREFIX AND SUFFIX GCD VALUES OF A GIVEN VECTOR    ////////////////////////////////
 vector<ll> pref(n),suff(n+1);
-->PREFIX<---
---------------------------
pref[0]=v[0];
for (ll i = 1; i < n;++i)
    {
        pref[i]=__gcd(pref[i-1],v[i]);
    }
-->SUFFIX<--
---------------------------
 for (ll i = n-1; i>=0; --i)
    {
        suff[i]=__gcd(suff[i+1],v[i]);
    }
*/
/*
///////////////////////////////////////////// HOW TO MAKE A PATTERN REPEAT ITSELF /////////////////////////////////////////////
--->REFENRENCE--->https://codeforces.com/contest/1699/problem/B
-------------------------------------------------------------------------------------------------------------------------------
        ll x,y;
        cin>>x>>y;
        vector<vector<ll>> v;
        v.push_back({1, 0, 0, 1});
        v.push_back({0, 1, 1, 0});
        v.push_back({0, 1, 1, 0});
        v.push_back({1, 0, 0, 1});
        fr(i,x){
            fr(j,y){
                cout<<v[i%4][j%4]<<" ";
            }
            cout<<endl;
        }
*/
/*
///////////////////////////////////////////// HOW TO KEEP ON TAKING ONE ELEMENT FROM THE BACK AND REMOVE ONE FROM THE FRONT
                                                    (THAT TOO VERY SELECTIVELY)            /////////////////////////////////////////////
//problem-->https://codeforces.com/contest/1690/problem/D
//the desired code-->
-------------------------------------------------------------------------------------------------
  ll ans=n;
   for (ll i = 0; i < n; ++i)
   {
       if(s[i]=='B')
       count_b++;
       else
       count_w++;
       if(count_b+count_w==k)
       {
           if(count_b==k)
           {
               cout<<0<<endl;
               return;
           }
           ans=min(ans,count_w);
           if(s[i-k+1]=='B')
           count_b--;
           else
           count_w--;
       }
*/

////////////////////////////////////////////  HOW CAN THE LAMBDA FUNCTIONS BE USED   ///////////////////////////////////////////////////////////
//problem-->https://codeforces.com/contest/1702/problem/D
/*
 string s ; cin >> s;
   vector<pair<char, ll>> v(s.length()); 
   ll sum = 0; 
   for (int i=0;i < s.length(); i++) {
      v[i].first = s[i]; 
      v[i].second = i; 
      sum += s[i] - 'a' + 1;  
   }
   ll p ; cin >> p;
   sort(all(v));
   reverse(all(v));              
   for(int i = 0 ; i < v.size(); ++i){
      if(sum <= p){
         break;
      }
      sum -= v[i].first - 'a' + 1;
      v[i].first = '-'; 
   }
   sort(all(v), [](pair<char, ll> a, pair<char, ll> b){
      return a.second < b.second;
   });
   for (int i=0; i<v.size() ;i++) {
      if (v[i].first != '-') {
         cout << v[i].first; 
      }
   }
   cout << endl;
*/
/// ------------------------------------FUNCTIONS 2.0---------------------------------------- ///
void printvector(vector<ll> &v)
{
    fr(i,v.size())
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

///////
void printarray(ll arr[],ll n)
{
    fr(i,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

///////

    
    

void solve()
{
    ll n;
    cin>>n;
    cout<<n<<endl;
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q;
cin>>q;
while(q--)
{
    solve();
}
    return 0;
}
/*
////////////// dfs ////////////////
using namespace std;
const ll N=1e9+10;
vector<ll> g[N];
bool vis[N];
void dfs(ll vertex)
{
vis[vertex]=true;
for(ll child:g[vertex])
{
    if(vis[child])continue;
    dfs(child);
}
}
*/






/*
 inp(n);
    inp(m);
    vector<ll> v(n);
    inpv(v);
    vector<ll> pref(n+1),suff(n+1);
    for(ll i=1;i<=n;++i)
    {
        pref[i]=pref[i-1]+v[i-1];
    }
    for(ll i=n-1;i>=0;--i)
    {
        suff[i]=suff[i+1]+v[i];
    }
    ll ans=1e18;
    for(ll i=0;i<=m;++i)
    {
        ll temp=pref[m-i]+suff[n-i];
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
*/









/*
/// ----------------------------------------------------------------------------------------------------------------- ///
//ceil(log2(x))
//is_sorted(all(v))
//is_sorted(s.begin(), s.end())
//number of subarrays in an array of size 'n' = (n*(n+1))/2;
//string upp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//string low="abcdefghijklmnopqrstuvwxyz";
//string num="0123456789";
//double sum=0;
//cout << fixed << setprecision(6) << sum << endl;
/// ----------------------------------------------------------------------------------------------------------------- ///
////////
bitset<64> b(n);
string s=b.to_string();
//n<=1e18 can be expressesed in 64 bit string
////////
stack,queue->no index access
use deque,vectors
-->assign(n,val)available for both
////////// working with iterators  //////////
auto it=upper_bound(all(v),i);
it--;
ll index=it-v.begin();
/////////////////////////////////////////////
string s="";
s.pb(9+'0');
s.pb('a');
s.pb('a'+2);
cout<<s<<endl;
cout<<s[0]-'0';
//9ac
//9
*/





/*
/////////////////////////////////////////////////////////// PBDS ////////////////////////////////////////////////////////
//for the 'less' one
//exactly functions like SET but with added benefits of-->count of the elements less than a particular value and indexing
//if written 'greater' instead of 'less'     --> values will be sorted in descending order then
//if written 'less_equal' instead of 'less'  --> works like MULTISET(duplicates will also exist then)
pbds A;
*A.find_by_order(x) -->returns the element present at the xth index
A.order_of_key(x)   -->returns the number of elements strictly lesser than x
A.erase(x)          -->if x is present then erases it from the ordered set
*******All the properties of SET like size(),begin(),end() can be used*******
1 2 7 8
*A.lower_bound(6) -->7
*A.lower_bound(2) -->2
*A.upper_bound(6) -->7
*A.upper_bound(2) -->7
printing the pbds -->similar to maps,sets and vectors
//all tc-->logn
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/



///////////////////////////////////////////////////////   A NEW LEARNING  ///////////////////////////////////////////////////////////////////
/*
 vector<vector<ll>> v(3,vector<ll>(3,0));
    for(ll i=0;i<3;++i)
    {
        for(ll j=0;j<3;++j)
        {
            cin>>v[i][j];
        }
    }
    //how to concatenate vectors one after another in a single vector
    vector<ll> temp;
    for(auto &i:v)
    {
        temp.insert(temp.end(),i.begin(),i.end());
    }
    printv(temp);
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





const ll int infLL=9223372036854775103;
const int inf=2147483643;
ll int mod=(ll)(1e9+7);
ll int ceil(ll int a,ll int b){return (a+b-1)/b;}
ll int min(ll int a, ll int b){if(a>b)return b;else return a;}
bool bit_check(ll int a,int i){
  if((a & (1LL<<i)))return 1;
  return 0;
}
ll int bit_toggle(ll int a,int i){
  return (a^(1LL<<i));
}
ll int bit_sum(ll int a,int i){
  return a+(1LL<<i);
}
ll int bit_sub(ll int a,int i){
  return a-(1LL<<i);
}
ll int mod_power(ll int x,ll int y){//x^y%p
  ll int p=mod;
  ll int res = 1;
  x = x % p;
  while (y > 0) { 
    if (y & 1)res = (res*x) % p;
    y = y>>1;x = (x*x) % p;
  }
  return res;
}
ll int power_of(ll int a,int b){
  if(a==0)return -1;
  return 1+power_of(a/b,b);
}
ll power(ll int a, ll int b) {
    if(a==1)return 1;
    ll int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


/// ---------------------------------------------------------------------------------------------- ///
// v[i]=pow(10,v[i])+0.1; 
// max 1e7 size vector can be created
// vector<vector<int>> M;
// M.resize(m, vector<int>(n));
// binary_search(all(v),5)-->returns boolean value
// iota(all(v),10); -- > o/p--> 10 11 12 13 14 15 16 17 18 19
// a + b = a ^ b + 2 * (a & b)

// bitset<32> b(n);
// string s=b.to_string();
// b.to_ullong()

//a^b=c^d is equal to a^d=b^c
///------------------------------------------------------------------------------------------------///







