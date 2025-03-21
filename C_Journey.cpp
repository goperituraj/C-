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
// int cnt=0;
vector<double> ans;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, double cnt, double prob)
{
    vis[node] = 1;
    bool f = true;
    ll c = 0;
    for (auto it : adj[node])
    {
        if (!vis[it])
            c++;
    }
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            f = false;
            dfs(it, adj, vis, cnt + 1, prob / (c));
        }
    }
    if (f)
    {
        // cout << prob << endl;
        // cout << cnt << endl;
        ans.push_back(prob * cnt);
    }
}
void solve()
{

    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0.000000000000 << endl;
        return;
    }
    vector<int> vis(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, adj, vis, 0.0, 1.0);
    double sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
    }
    // sum = sum / ans.size();
    cout << fixed << setprecision(10) << sum << endl;
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