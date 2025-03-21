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
// void bfs(int node,vector<vector<int>>&adj){

// }
void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        adj[v[i]].push_back(i);
    }
    queue<int> q;
    // for (int i = 0; i < adj.size(); i++)
    // {
    //     for (auto it : adj[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }

    q.push(1);
    ll cnt = 0;
    while (!q.empty())
    {
        cnt += (q.size()) % 2;
        // cout << q.size() << endl;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                q.push(it);
            }
        }
    }
    cout << cnt << endl;
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