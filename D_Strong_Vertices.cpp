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
    vector<ll> u(n);
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = u[i] - v[i];
        vp[i] = {v[i], i + 1};
    }
    sort(vp.begin(), vp.end());
    ll x = vp[n - 1].first;
    vector<ll> ans;
    // ans.push_back(vp[n - 1].second);
    for (int i = 0; i < n; i++)
    {
        if (vp[i].first == x)
        {
            ans.push_back(vp[i].second);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
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