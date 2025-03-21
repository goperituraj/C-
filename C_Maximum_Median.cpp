#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll mid = n / 2;

    for (ll i = mid + 1; i < n && k > 0; i++)
    {
        ll gap = v[i] - v[mid];
        ll count = i - mid;
        ll cost = gap * count;

        if (k >= cost)
        {
            v[mid] = v[i];
            k -= cost;
        }
        else
        {
            v[mid] += k / count;
            k = 0;
        }
    }

    if (k > 0)
    {
        v[mid] += k / (n - mid);
    }

    cout << v[mid] << endl;
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
