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

    ll n, x, y;
    cin >> n >> x >> y;
    map<pair<ll, ll>, ll> mp;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    mp[{v[0] % x, v[0] % y}]++;
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        ll xdiv = v[i] % x;
        ll ydiv = v[i] % y;
        cnt += mp[{(x - xdiv) % x, ydiv}];
        mp[{xdiv, ydiv}]++;
    }
    cout << cnt << endl;
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