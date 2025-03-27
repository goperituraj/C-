// Step-by-step guide:
// 1. Read the problem statement carefully.
// 2. Visualize and dry-run examples.
// 3. Implement the solution here.
// 4 .In directed graph dfs dont work in cycle detection
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll n, m;
vector<vector<pair<ll, ll>>> adj(1e6 + 1);
vector<ll> isvis(1e6 + 1, 0);
vector<ll> par(1e6 + 1);
void dfs(ll node, ll sum)
{
    // cout << "he" << endl;
    isvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it.first])
        {
            par[it.first] = node;
            sum += it.second;
            dfs(it.first, sum);
        }
        else if (isvis[it.first] == 1)
        {
            sum += it.second;
            if (sum < 0)
            {
                cout << "YES" << endl;
                vector<ll> ans;
                ans.push_back(it.first);
                while (par[node] != node)
                {
                    ans.push_back(node);
                    node = par[node];
                }
                ans.push_back(ans[0]);
                reverse(ans.begin(), ans.end());
                // cout << sum << endl;
                for (auto it : ans)
                {
                    cout << it << " ";
                }
                exit(0);
            }
        }
    }
    isvis[node] = 0;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    // cout << "he" << endl;
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        // cout << "he" << endl;
        adj[x].push_back({y, z});
    }
    // cout << "he" << endl;
    for (ll i = 1; i <= n; i++)
    {
        if (!isvis[i])
        {
            dfs(i, 0);
        }
    }
    cout << "NO" << endl;
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