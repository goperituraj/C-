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
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        ll x = k - v[i] % k;
        if (x == k)
            continue;
        mp[x]++;
    }
    ll max_key = -1, max_value = -1;

    for (auto it : mp)
    {
        if (it.second >= max_value)
        {
            max_value = it.second;
            max_key = max(it.first, max_key);
        }
    }
    ll ans = max_key + (max_value - 1) * k + 1;
    if (ans < 0)
        ans = 0;
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