#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<int> parent;
vector<int> ans;
vector<vector<int>> fans;

void dfs(int node, vector<vector<int>> &adj, vector<int> &isvis)
{
    isvis[node] = 1;
    ans.push_back(node);

    bool hasUnvisitedChild = false;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            hasUnvisitedChild = true;
            dfs(it, adj, isvis);
        }
    }

    if (!hasUnvisitedChild)
    {
        reverse(ans.begin(), ans.end());
        fans.push_back(ans);
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    parent.assign(n + 1, -1);
    vector<int> isleaf(n + 1, 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        isleaf[v[i]] = 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == v[i])
            continue;
        adj[i].push_back(v[i]);
    }

    vector<int> leaves;
    for (int i = 1; i <= n; i++)
    {
        if (isleaf[i])
        {
            leaves.push_back(i);
        }
    }

    vector<int> isvis(n + 1, 0);
    ans.clear();
    fans.clear();

    for (int leaf : leaves)
    {
        if (!isvis[leaf])
        {
            ans.clear();
            dfs(leaf, adj, isvis);
        }
    }

    int nn = fans.size();
    if (nn == 0)
    {
        cout << "1\n1\n1\n\n";
        return;
    }
    cout << nn << endl;
    for (int i = 0; i < nn; i++)
    {
        cout << fans[i].size() << endl;
        for (int v : fans[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
