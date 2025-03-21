#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    vector<tuple<ll, int, int>> v;
    v.reserve(3 * m);

    for (ll i = 0; i < n; i++)
    {
        ll x = a[i], r = b[i], r2 = r * r;
        for (ll d = -r; d <= r; d++)
        {
            ll nx = x + d, d2 = d * d;
            int y = (int)floor(sqrt((long double)(r2 - d2)));
            v.push_back({nx, -y, y});
        }
    }

    sort(v.begin(), v.end(), [](const auto &p, const auto &q)
         { return (p < q); });

    ll ans = 0;
    vector<int> yv;

    for (int i = 0; i < v.size();)
    {
        ll x = get<0>(v[i]);
        int yl = get<1>(v[i]), yh = get<2>(v[i]);
        int j = i + 1;

        while (j < v.size() && get<0>(v[j]) == x)
        {
            yl = min(yl, get<1>(v[j]));
            yh = max(yh, get<2>(v[j]));
            j++;
        }

        yv.push_back(yl);
        yv.push_back(yh);

        ans += (yh - yl + 1);
        i = j;
    }

    sort(yv.begin(), yv.end());
    int y = 0;
    bool f = binary_search(yv.begin(), yv.end(), y);

    cout << ans << "\n";
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
