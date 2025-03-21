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

    ll n, g, b;
    cin >> n >> g >> b;
    ll dn = n;
    n = (n + 1) / 2;
    ll m = n / g;
    if (n % g != 0)
        m++;
    if (m > 0)
        m--;
    if (m * b < dn - n)
    {
        cout << dn << endl;
        return;
    }
    ll ans = m * b + n;
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