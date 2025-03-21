#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 998244353;
const ll INF = 1e18;

ll f(ll i, ll liars, vector<ll> &v, map<pair<ll, ll>, ll> &dp)
{
    ll n = v.size();
    if (i >= n)
        return 1;

    if (dp.find({i, liars}) != dp.end())
        return dp[{i, liars}];

    ll h = 0, nh = 0;

    if (v[i] == liars)
    {
        h += f(i + 1, liars, v, dp);
        if ((i < n - 1 && v[i + 1] == liars + 1) || (i == n - 1))
            nh = (nh + f(i + 2, liars + 1, v, dp)) % MOD;
    }
    else
    {
        if ((i < n - 1 && v[i + 1] == liars + 1) || (i == n - 1))
            nh = nh + f(i + 2, liars + 1, v, dp) % MOD;
    }

    return dp[{i, liars}] = (h + nh) % MOD;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<pair<ll, ll>, ll> dp;
    cout << f(0, 0, v, dp) << endl;
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
