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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, 1e12));
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ans[x][y] = min(ans[x][y], z);
        ans[y][x] = min(ans[y][x], z);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] == 1e12)
            {
                ans[i][j] = -1;
            }
        }
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
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