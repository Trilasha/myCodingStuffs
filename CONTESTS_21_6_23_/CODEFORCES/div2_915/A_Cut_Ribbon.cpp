#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll fun(ll n, vector<ll> &arr, ll ind, vector<vector<ll>> &dp)
{
    if (n == 0)
        return 1;
    if(n < 0)
    return LLONG_MIN;
    if (ind == arr.size())
    {
        return LLONG_MIN;
    }
    if (dp[n][ind] != -1)
        return dp[n][ind];
    ll take = LLONG_MIN, notTake = LLONG_MIN;
    if (arr[ind] <= n)
    {
        ll val = fun(n - arr[ind], arr, ind, dp);
        if (val != LLONG_MIN)
            take = 1 + val;
    }
    notTake = fun(n, arr, ind + 1, dp);
    return dp[n][ind] = max(take, notTake);
}
int main()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> arr = {a, b, c};
    vector<vector<ll>> dp(n + 1, vector<ll>(3, -1));
    cout << fun(n, arr, 0, dp) << endl;
}