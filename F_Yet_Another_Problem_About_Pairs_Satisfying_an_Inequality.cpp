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

    ll cnt = 0;
    vector<pair<ll, ll>> vp;

    // Store pairs of (x, index) where x < 0
    for (ll i = 0; i < n; i++)
    {
        ll x = v[i] - (i + 1);
        if (x < 0)
        {
            vp.push_back({x, i}); // Store both x and index
        }
    }

    // Sort the vector by x and then by index
    sort(vp.begin(), vp.end());

    // Count valid pairs
    for (ll i = 0; i < vp.size(); i++)
    {
        ll idx = vp[i].second;
        // Find the first pair with an index greater than the current index
        auto it = upper_bound(vp.begin() + i + 1, vp.end(), make_pair(INF, idx),
                              [](const pair<ll, ll> &a, const pair<ll, ll> &b)
                              {
                                  return a.second < b.second;
                              });
        cnt += distance(it, vp.end());
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
