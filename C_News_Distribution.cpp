#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &vis, ll &cnt, ll &cur)
{

    vis[node] = cur;
    for (auto it : adj[node])
    {
        if (vis[it] != cur)
        {
            cnt++;
            dfs(it, adj, vis, cnt, cur);
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u;
        cin >> u;
        if (u > 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            ll last = b;
            if (u > 2)
            {
                for (int j = 2; j < u; j++)
                {
                    cin >> a;
                    adj[last].push_back(a);
                    adj[a].push_back(last);
                    last = a;
                }
            }
        }
        if (u == 1)
        {
            ll c;
            cin >> c;
        }
    }
    vector<ll> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll cnt = 1;
        ll cur = i;
        dfs(i, adj, vis, cnt, cur);
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}