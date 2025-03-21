// Read the question correctly with proper dry run of given test cases
// Visulaize the problem
// then get the solution and then code
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int node, vector<vector<int>> &adj, vector<int> &isvis)
{
    isvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            // isvis[it] = 1;
            dfs(it, adj, isvis);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> isvis(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!isvis[i])
        {
            ans.push_back(i);
            dfs(i, adj, isvis);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}