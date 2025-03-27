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
ll f(ll m, ll x)
{
    x++;
    ll b = m / x;
    ll r = m % x;
    return b * (x - 1) + min(x - 1, r);
}
void solve()
{

    ll n, m, k;
    cin >> n >> m >> k;

    ll lo = 1, hi = m, ans = m;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll c = f(m, mid);
        if (n * c >= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
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