//src -> https://codeforces.com/blog/entry/61221

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <math.h>
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <ll,ll>
#define N 200005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

vector <ll> divisors(int n)
{
    vector <ll> v;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            v.push_back(i);
            if(n/i != i)
                v.push_back(n/i);
        }
    }
    return v;
}
ll ncr(int n,int r)
{
    if(n < r)
        return 0;
    if(n - r < r)
        r = n - r;
    ll res = 1;
    for (int i = 1; i <= r; ++i)
    {
        res *= n;
        res /= i;
        n--;
    }
    return res;
}

int main()
{
    int n,A[N];
    ll cnt[500],ans = 0,x;
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    vector <ll> div = divisors(x);
    sort(all(div));
    int sz = div.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < sz; ++j)
        {
            if(A[i] == div[j])
            {
                cnt[j]++;
                break;
            }    
        }
    }
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i; j < sz; ++j)
        {
            for (int k = j; k < sz; ++k)
            {
                
                if(div[i]*div[j] > x/div[k])  continue;
                if(div[i]*div[j]*div[k] != x)  continue;


                if(i == j && j == k)
                {
                    ans += ncr(cnt[i],3);
                }
                else if(i == j)
                {
                    ans += ncr(cnt[i],2)*cnt[k];
                }
                else if(j == k)
                {
                    ans += ncr(cnt[j],2)*cnt[i];
                }
                else
                {
                    ans += cnt[i]*cnt[j]*cnt[k];
                }
            }
        }
    }
    cout << ans;
}