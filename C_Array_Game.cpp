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
        cin >> v[i];
    }

    if (k >= 3)
    {
        cout << 0 << endl;
        return;
    }
    sort(v.begin(), v.end());
    ll ans = v[0];
    sort(v.begin(), v.end());

    if (k == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, v[i + 1] - v[i]);
        }
        cout << ans << endl;
    }
    else
    { // k == 2
        vector<ll> a;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                a.push_back(abs(v[j] - v[i]));
                ans = min(ans, v[j] - v[i]);
            }
                }

        for (int i = 0; i < a.size(); i++)
        {
            int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            if (p < n)
                ans = min(ans, abs(v[p] - a[i]));
            if (p > 0)
                ans = min(ans, abs(v[p - 1] - a[i]));
        }
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
