using namespace std;
bool check(ll mid,ll pf[],ll v)
{
    return (pf[mid]>=v);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        fr(i,n)
        cin>>arr[i];
        dsort(arr);
        ll pf[n];
        fr(i,n)
        pf[i]=0;
        pf[0]=arr[0];
        for (ll i =1; i < n; i++)
        {
            pf[i]=pf[i-1]+arr[i];
        }
        while (q--)
        {
            ll v;
            cin>>v;
            ll left=0,right=n-1;
            ll mid;
            while(right-left>1)
            {
                mid=(left+right)/2;
                if(check(mid,pf,v))
                right=mid;
                else
                left=mid+1;
            }
            if(check(left,pf,v))
            cout<<left+1<<endl;
            else if(check(right,pf,v))
            cout<<right+1<<endl;
            else
            cout<<-1<<endl;
        }
        
    }
    
    return 0;
}