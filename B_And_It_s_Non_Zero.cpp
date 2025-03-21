#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<vector<ll>> b(2e5 + 3, vector<ll>(32, 0));

void p()
{
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            b[i][j] = b[i - 1][j];
            if (i & (1 << j))
            {
                b[i][j]++;
            }
        }
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll ans = INF;
    for (int j = 0; j < 32; j++)
    {

        ll setBitsInRange = b[r][j] - b[l - 1][j];
        ans = min(ans, (r - l + 1) - setBitsInRange);
    }

    cout << ans << endl;
}

int main()
{
    fastio();
    p();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
