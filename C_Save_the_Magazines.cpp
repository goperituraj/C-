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

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll cnt = 0;
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
        else if (cnt > 0)
        {
            // if (i - cnt - 1 >= 0)
            // {

            vp.push_back({i - cnt - 1, i - 1});
            // }
            // else
            // {
            //     vp.push_back({i - cnt, i - 1});
            // }
            cnt = 0;
        }
    }
    if (cnt > 0)
    {
        // if (n - cnt - 1 >= 0)
        // {

        vp.push_back({n - cnt - 1, n - 1});
        // }
        // else
        // {
        //     vp.push_back({n - cnt, n - 1});
        // }
    }
    ll fsum = 0;
    for (int i = 0; i < vp.size(); i++)
    {
        ll l = vp[i].first;
        ll r = vp[i].second;
        ll mn = INF;
        ll sum = 0;
        for (int j = max((ll)0, l); j <= r; j++)
        {
            mn = min(mn, v[j]);
            sum += v[j];
        }
        if (l >= 0)
            fsum += sum - mn;
        else
            fsum += sum;
    }
    cout << fsum << endl;
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