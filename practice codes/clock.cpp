/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
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
    
    
    
using namespace std;
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
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
    string s;
    ll x;
    cin>>s>>x;
    ll ct=0;
    string s2;
    fr(i,s.size())
    {
        if(s[i]!=':')
        s2.pb(s[i]);
    }
    string x2;
    ll n1=x/60;
    ll n2=x%60;
    if(n1<10)
    {
        x2.pb('0');
        x2.pb('0'+n1);
    }
    else
    x2.pb('0'+n1);
    if(n2<10)
    {
        x2.pb('0');
        x2.pb('0'+n2);
    }
    else
    x2.pb('0'+n2);
   cout<<stoi(s2)<<endl;
    cout<<stoi(x2)<<endl;
   string ans;
   string ori=s2;
   while(1)
   {
     ans=to_string(stoi(s2)+stoi(x2));
    if(ans.size()==3)
    {
        reverse(ans.begin(),ans.end());
        ans.pb('0');
        reverse(ans.begin(),ans.end());
    }
     if(ans.size()==2)
    {
        reverse(ans.begin(),ans.end());
        ans.pb('00');
        reverse(ans.begin(),ans.end());
    }
     if(ans.size()==1)
    {
        reverse(ans.begin(),ans.end());
        ans.pb('000');
        reverse(ans.begin(),ans.end());
    }
    if(stoi(ans)>2400)
    {
       ans=findDiff(ans,"2400");
    }
    if(stoi(ans)==stoi(ori))
    break;
   if(Is_Palindrome(ans))
   ct++;
   s2=ans;
   ans="";
   }
   cout<<ct<<endl;

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