#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll INF = 1e18;

ll dfs(int node, vector<vector<int>> &adj, vector<ll> &v)
{
    ll ans = INF;
    for (auto it : adj[node])
    {
        ans = min(dfs(it, adj, v), ans);
    }
    if (node == 1)
    {
        v[node] += ans;
        return v[node];
    }
    if (ans != INF && ans > v[node])
    {
        v[node] += abs((ans - v[node])) / 2;
    }
    else if (ans != INF && ans <= v[node])
    {
        return ans;
    }
    return v[node];
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        adj[p[i]].push_back(i);
    }
    cout << dfs(1, adj, v) << endl;
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
