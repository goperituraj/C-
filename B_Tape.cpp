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

    ll n, len, cnt;
    cin >> n >> len >> cnt;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> diff;
    for (int i = 0; i < n - 1; i++)
    {
        diff.push_back(v[i + 1] - v[i]);
    }
    sort(diff.rbegin(), diff.rend());
    ll ans = cnt;
    for (int i = cnt - 1; i < diff.size(); i++)
    {
        ans += diff[i];
    }
    cout << ans << endl;
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}