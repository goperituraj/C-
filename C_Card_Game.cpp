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

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        if (v[0] > 0)
            cout << v[0] << endl;
        else
            cout << 0 << endl;
        return;
    }
    ll sum = 0;
    for (int i = 2; i < n; i++)
    {
        if (v[i] > 0)
            sum += v[i];
    }
    if (v[0] >= 0 && v[1] >= 0)
        sum += v[0] + v[1];
    if (v[0] >= 0 && v[1] < 0)
        sum += v[0];
    if (v[0] < 0 && v[1] > 0)
    {
        sum += max(0ll, v[0] + v[1]);
    }
    cout << sum << endl;
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