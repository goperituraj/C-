#include <bits/stdc++.h>
using namespace std;

int n, m;

void bfs(int s, vector<vector<int>> &adj, vector<int> &parent)
{
    vector<int> isvis(n + 1, 0);
    queue<int> q;
    q.push(s);
    isvis[s] = 1;   // Mark source as visited
    parent[s] = -1; // Source has no parent

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Check if we reached the destination node
        if (node == n)
        {
            vector<int> ans;
            int x = n;
            while (x != -1)
            {
                ans.push_back(x);
                x = parent[x];
            }
            reverse(ans.begin(), ans.end());

            // Output the path length and the path
            cout << ans.size() << endl;
            for (int v : ans)
            {
                cout << v << " ";
            }
            cout << endl;
            return;
        }

        for (int neighbor : adj[node])
        {
            if (!isvis[neighbor])
            {
                q.push(neighbor);
                isvis[neighbor] = 1;
                parent[neighbor] = node;
            }
        }
    }

    // If we finish the loop without finding the destination
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(1, adj, parent);
    return 0;
}
