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
    ll ix = 0, iy = 0;
    ll a, b;
    cin >> a >> b;
    ix += a;
    iy += b;
    ll f = ix;
    ll m = iy;
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        ix += a;
        iy += b;
    }
    ix += k;
    iy += k;
    ll ans = 2 * (iy - m) + 2 * (ix - f);
    cout << ans << endl;
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