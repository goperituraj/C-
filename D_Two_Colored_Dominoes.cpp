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

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'L' || v[i][j] == 'D' || v[i][j] == 'R' || v[i][j] == 'U')
                cnt++;
        }
        if (cnt % 2 != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'L' || v[j][i] == 'D' || v[j][i] == 'R' || v[j][i] == 'U')
                cnt++;
        }
        if (cnt % 2 != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'U')
            {
                        }
        }
    }
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