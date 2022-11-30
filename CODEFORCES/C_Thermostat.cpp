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
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t) {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///

    


void solve()
{
   ll l,r,x;
   cin>>l>>r>>x;

   ll a,b;
   cin>>a>>b;

   if(a==b)
   {
    cout<<0<<endl;
    return;
   }




   else if(a<b)
   {
    ll diff=abs(a-b);

    if(diff>=x)
    {
        cout<<1<<endl;
        return;
    }
    else if(diff<x)
    {

        ll chk=0;
        ll var=a;
        var=var-x;
        if(var>=l || (r-b)>=x)
        {
            cout<<2<<endl;
            return;
        }
        // else if((r-b)>=x)
        // {
        //     cout<<2<<endl;
        //     return;
        // }
        // else 
        // {
        //     cout<<-1<<endl;
        //     return;
        // }
        else 
        {
            ll chka=0;
            ll chkb=0;
            ll chkc=0;

            if((a+x)<=r)
            chka=1;

            if(abs(b-l)>=x)
            chkb=1;

            if(chka==1 && chkb==1)
            {
                cout<<3<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
    return;
   }


   else if(a>b)
   {
    ll diff2=abs(a-b);

    if(diff2>=x)
    {
        cout<<1<<endl;
        return;
    }
    else if(diff2<x)
    {

       // ll chk=0;
       ll temp=a;
        temp=temp+x;
        if(temp<=r)
        {
            cout<<2<<endl;
            return;
        }
        else if(abs(l-b)>=x)
        {
            cout<<2<<endl;
            return;
        }
        else
        {
            ll chkaa=0;
            ll chkbb=0;
            ll chkc=0;

            if((a-x)>=l)
            chkaa=1;

            if(abs(b-r)>=x)
            chkbb=1;

            if(chkaa==1 && chkbb==1)
            {
                cout<<3<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
    return;
   }
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















