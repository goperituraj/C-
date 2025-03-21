// Step-by-step guide:
// 1. Read the problem statement carefully.
// 2. Visualize and dry-run examples.
// 3. Implement the solution here.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> diff(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        diff[i] = v[i] - i;
    }
    vector<ll> dp(n + 1, 0);
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        dp[i] += v[i];
        if (mp.find(diff[i]) != mp.end())
        {
            dp[i] += dp[mp[diff[i]]];
        }
        mp[diff[i]] = i;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}