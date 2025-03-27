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
vector<ll> vis(1e7, 0);
ll n, m;
void dfs(ll node, vector<ll> &dis, vector<vector<pair<ll, ll>>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {

        if (!vis[it.first] || it.first == n)
        {
            if (dis[node] + it.second > dis[it.first] || dis[it.first] == -1e10)
            {
                dis[it.first] = dis[node] + it.second;
                dfs(it.first, dis, adj);
            }
        }
    }
}
void solve()
{

    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    vector<ll> dis(n + 1, -1e10);
    dis[1] = 0;
    dfs(1, dis, adj);
    cout << dis[n];
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}