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
    vector<ll> v(n);
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]].push_back(i + 1);
    }
    vector<ll> ans(n + 1, -1);
    for (auto it : mp)
    {
        ll mx = 0;
        vector<ll> temp;
        temp.push_back(0);

        for (int j = 0; j < it.second.size(); j++)
        {
            temp.push_back(it.second[j]);
        }
        temp.push_back(n + 1);
        for (int i = 0; i < temp.size() - 1; i++)
        {
            mx = max(mx, temp[i + 1] - temp[i]);
        }
        for (int j = mx; j <= n; j++)
        {
            if (ans[j] != -1)
                break;
            ans[j] = it.first;
        }
    }
    for (int i = 1; i <= n; i++)
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