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
    if (k >= n)
    {
        cout << 1 << endl;
    }
    else
    {
        ll ans = n;
        for (ll j = 1; j * j <= n; j++)
        {
            if (n % j == 0)
            {
                if (j <= k)
                {
                    ans = min(ans, n / j);
                }

                if (n / j <= k)
                {
                    ans = min(ans, j);
                }
            }
        }
        cout << ans << endl;
        return;
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