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

    vector<ll> p(n), p2(n);
    map<ll, ll> mp, mp2, mp3;
    ll mx = 0, mx2 = 0;
    ll sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        sum += v[i];
        if (mp[v[i]] >= 2)
        {
            mx = max(mx, v[i]);
        }
        p[i] = mx;
    }

    for (int i = 0; i < n; i++)
    {
        mp2[p[i]]++;
        sum += p[i];
        if (mp2[p[i]] >= 2)
        {
            mx2 = max(mx2, p[i]);
        }
        p2[i] = mx2;
        mp3[p2[i]]++;
    }

    for (int i = 0; i < n; ++i)
        sum += (n - i) * 1LL * p2[i];

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
