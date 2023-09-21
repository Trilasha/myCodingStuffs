class BIT{
    vector<ll> bit;
public:
    BIT(ll n)
    {
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n)
    {
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x)
    {
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};
//BIT bt(n);
//for(ll i=1;i<=n;++i){
//bt.update(i,temp[i],n);
//1-based indexing so input in vector from 1 to <=n
