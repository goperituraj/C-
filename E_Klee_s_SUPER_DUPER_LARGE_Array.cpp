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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        v[i] = k;
        k++;
    }
    vector<ll> a(n);
    a[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + v[i];
    }
    vector<ll> b(n);
    b[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = v[i] + b[i + 1];
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            ans = min(ans, abs(a[i] - b[i + 1]));
        else
        {
            ans = min(ans, a[i]);
        }
    }
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