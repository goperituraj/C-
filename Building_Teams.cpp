#include <bits/stdc++.h>
using namespace std;
int n, m;
bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
{
    color[node] = col;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !col, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == col)
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 1, adj, color))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            cout << 2 << " ";
        else
            cout << color[i] << " ";
    }
}