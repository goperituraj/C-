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
    vector<ll> v(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> diff;
    for (int i = 0; i < k - 1; i++)
    {
        diff.push_back(v[i + 1] - v[i] - 1);
    }
    diff.push_back(n - v[k - 1] + v[0] - 1);
    sort(diff.begin(), diff.end());

    ll s = diff.size();
    ll p = 0;
    if (diff[s - 1] == 0)
        p = 0;
    else if (diff[s - 1] == 1)
        p = 1;
    else
        p = diff[s - 1] - 1;

    vector<ll> t(s);
    for (int i = 0; i < s; i++)
    {
        if (diff[i] % 2 != 0)
        {
            t[i] = diff[i] / 2 + 1;
        }
        else
        {
            t[i] = diff[i] / 2;
        }
    }

    for (int i = s - 2; i >= 0; i--)
    {
        ll l = s - 1 - i;
        if (2 * l <= t[i])
        {
            ll m = diff[i] - 4 * l;
            if (m == 1)
                p++;
            else if (m > 1)
                p += m - 1;
        }
        else
            break;
    }

    cout << n - p << endl;
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
