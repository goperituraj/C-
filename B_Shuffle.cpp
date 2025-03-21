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

    ll n, x, m;
    cin >> n >> x >> m;
    vector<vector<ll>> v(m, vector<ll>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }
    bool f = false;
    ll mn = 1e18;
    ll mx = -1e18;
    ll l = x, r = x;

    for (int i = 0; i < m; i++)
    {
        if (!f && (v[i][0] <= l && l <= v[i][1] || v[i][0] <= r && r <= v[i][1]))
        {
            f = true;
        }
        if (f)
        {
            mn = min(mn, v[i][0]);
            mx = max(mx, v[i][1]);
            f = false;
            l = mn;
            r = mx;
        }
    }
    cout << (r - l + 1) << endl;
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