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
ll f(ll idx, vector<ll> &v, vector<ll> &dp)
{
    ll n = v.size();
    if (idx == n)
        return 0;
    if (idx > n)
        return 1e17;
    if (dp[idx] != -1)
        return dp[idx];
    ll rem = 0, notrem = 0;
    rem += 1 + f(idx + 1, v, dp);
    notrem += f(idx + v[idx] + 1, v, dp);
    return dp[idx] = min(rem, notrem);
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
    vector<ll> dp(n + 2, -1);
    cout << f(0, v, dp) << endl;
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