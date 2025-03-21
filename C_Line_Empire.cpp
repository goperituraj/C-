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

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << (b * v[0]) << endl;
        return;
    }
    if (a <= b)
    {
        ll d = v[0];
        for (int i = 1; i < n - 1; i++)
        {
            d += v[i] - v[i - 1];
        }
        d *= (a + b);
        d += (v[n - 1] - v[n - 2]) * b;
        cout << d << endl;
        return;
    }
    else
    {
        ll d = 0;
        d = a / b;
        if (a % b)
        {
            d++;
        }
        d = min(n, d);
        ll ans = 0;
        for (int i = 0; i < n - d; i++)
        {
            if (i == 0)
            {
                ans += v[i];
            }
            else
                ans += v[i] - v[i - 1];
        }
        ll temp = 0;
        for (int i = n - 1; i >= n - d; i--)
        {
            temp += v[i];
        }
        if (n - d - 1 >= 0)
            temp -= d * v[n - d - 1];

        ans *= (a + b);
        ans += (temp * b);
        cout << ans << endl;
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