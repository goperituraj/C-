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

    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k + 5, vector<ll>(n + 4));
    for (int j = 1; j <= n; j++)
    {
        dp[k - 1][j] = n / j;
    }
    for (int i = k - 2; i >= 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = j; k <= n; k += j)
            {
                dp[i][j] = (dp[i][j] + dp[i + 1][k]) % MOD;
            }
        }
    }
    // cout << "DP Table:" << endl;
    // for (ll i = 0; i < k; i++)
    // {
    //     cout << "k = " << i + 1 << ": ";
    //     for (ll j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // ll ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans += dp[0][i];
    // }
    cout << dp[0][1] % MOD << endl;
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