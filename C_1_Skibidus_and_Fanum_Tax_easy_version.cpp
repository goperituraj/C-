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

    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    vector<ll> t(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    vector<ll> dup(n);
    for (int i = 0; i < n; i++)
    {
        dup[i] = t[0] - v[i];
    }
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        ll mn = min(v[i], dup[i]);
        if (i == 0)
            ans.push_back(mn);
        else if (i > 0 && mn >= ans.back())
        {
            ans.push_back(mn);
        }
        else
        {
            ans.push_back(max(v[i], dup[i]));
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
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