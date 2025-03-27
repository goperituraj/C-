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
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        // adj[y].push_back({x, z});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
    vector<ll> dis(n + 1, INF);
    dis[1] = 0;

    while (!q.empty())
    {
        auto front = q.top();
        q.pop();
        ll wt = front.first;
        ll node = front.second;
        if (wt > dis[node])
            continue;
        for (auto it : adj[node])
        {
            if (wt + it.second < dis[it.first])
            {
                dis[it.first] = wt + it.second;
                q.push({dis[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (dis[i] == 1e18 ? -1 : dis[i]) << " ";
    }
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