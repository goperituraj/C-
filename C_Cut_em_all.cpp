#include <bits/stdc++.h>
using namespace std;
int dfs(int node, vector<vector<int>> &adj, vector<int> &isvis, vector<int> &ss)
{
    isvis[node] = 1;
    ss[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            ss[node] += dfs(it, adj, isvis, ss);
        }
    }
    return ss[node];
}
int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> adj(n + 1);
    vector<int> isvis(n + 1, 0);
    vector<int> ss(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, adj, isvis, ss);
    int c = 0;
    for (auto it : ss)
    {
        // cout << it << " ";
        if (it % 2 == 0)
            c++;
    }
    cout << c - 2 << endl;
    return 0;
}
