#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool compareRows(const vector<ll> &a, const vector<ll> &b)
{
    ll maxA = a[0], indexA = 0;
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] > maxA)
        {
            maxA = a[i];
            indexA = i;
        }
    }
    ll maxB = b[0], indexB = 0;
    for (int i = 1; i < b.size(); ++i)
    {
        if (b[i] > maxB)
        {
            maxB = b[i];
            indexB = i;
        }
    }
    if (maxA != maxB)
    {
        return maxA < maxB;
    }
    return indexA < indexB;
}

bool check(vector<ll> &v, ll p)
{
    ll n = v.size();
    for (int i = 0; i < n; i++)
    {

        if (p <= v[i])
        {
            return false;
        }
        p++;
    }

    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        vector<ll> k(m);
        for (int j = 0; j < m; j++)
        {
            cin >> k[j];
        }
        v[i] = k;
    }
    vector<pair<ll, ll>> fans;
    // sort(v.begin(), v.end(), compareRows);
    for (int i = 0; i < n; i++)
    {
        ll low = 1, high = 1e18, ans;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (check(v[i], mid))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        fans.push_back({ans, v[i].size()});
    }
    sort(fans.begin(), fans.end());
    ll l = fans[0].first, r = fans[n - 1].first;
    ll a = 1e12;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll curr = mid;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (curr >= fans[i].first)
            {
                curr += fans[i].second;
            }
            else
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            a = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << a << endl;

    // cout <<  << endl;
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
