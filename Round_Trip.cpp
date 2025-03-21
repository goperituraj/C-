#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> isvis;
int ep;
void dfs(int node, int p, vector<vector<int>> &adj, vector<int> &parent)
{
    parent[node] = p;
    isvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            dfs(it, node, adj, parent);
        }
        else if (it != p)
        {
            ep = it;
            // parent[it] = p;
            int x = node;
            vector<int> ans;
            ans.push_back(ep);
            while (x != ep)
            {
                ans.push_back(x);
                x = parent[x];
            }
            ans.push_back(ep);
            reverse(ans.begin(), ans.end());
            // cout << ans.size() << endl;
            for (auto v : ans)
            {
                cout << v << " ";
            }
            return;
        }
    }
}
int main()
{
    ep = -1;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> parent(n + 1, -1);
    isvis.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!isvis[i])
        {
            dfs(i, -1, adj, parent);
            // if (ep != -1)
            //     break; // Exit once a cycle is found
        }
    }
    if (ep == -1)
    {
        cout << "IMPOSSIBLE";
    }
}