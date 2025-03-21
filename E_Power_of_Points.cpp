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
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<ll> ans(n, 0);

    sort(v.begin(), v.end());

    vector<ll> ps(n), ss(n);
    ps[0] = v[0].first;
    for (ll i = 1; i < n; i++)
        ps[i] = ps[i - 1] + v[i].first;

    ss[n - 1] = v[n - 1].first;
    for (ll i = n - 2; i >= 0; i--)
        ss[i] = ss[i + 1] + v[i].first;

    for (ll i = 0; i < n; i++)
    {
        ll res = 0;
        if (i == 0)
        {
            res = abs(ss[i + 1] - (n - 1) * v[i].first) + (n - 1) + 1;
        }
        else if (i == n - 1)
        {
            res = abs(ps[i - 1] - (n - 1) * v[i].first) + (n - 1) + 1;
        }
        else
        {
            res = abs(ss[i + 1] - (n - i - 1) * v[i].first) + (n - i - 1);
            res += abs(ps[i - 1] - i * v[i].first) + i;
            res++;
        }
        ans[v[i].second] = res;
    }

    for (ll i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << endl;
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
