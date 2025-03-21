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
    ll dn = n;
    ll cnt2 = 0;
    while (n % 2 == 0)
    {
        cnt2++;
        n = n / 2;
    }
    ll cnt5 = 0;
    while (n % 5 == 0)
    {
        n = n / 5;
        cnt5++;
    }
    ll ans = 1;
    while (cnt2 > cnt5 && ans * 5 <= m)
    {
        ans = ans * 5;
        cnt5++;
    }
    while (cnt2 < cnt5 && ans * 2 <= m)
    {
        ans = ans * 2;
        cnt2++;
    }
    while (ans * 10 <= m)
    {
        ans = ans * 10;
    }
    ll x = m / ans * ans;
    cout << dn * x << endl;
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