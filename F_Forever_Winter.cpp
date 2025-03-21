#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> mp;

    for (int j = 1; j <= n; j++)
    {
        int x = adj[j].size();
        if (x != 0)
            mp[x]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    int x = -1;

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            cout << it.first << " ";
            x = it.first;
        }
    }

    for (auto it : mp)
    {
        if (it.second == x)
        {
            cout << it.first - 1 << endl;
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
