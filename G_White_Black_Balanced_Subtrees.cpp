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
string s;
ll fans = 0;
pair<ll, ll> count(ll node, vector<vector<ll>> &adj, vector<ll> &isvis)
{
    isvis[node] = 1;
    ll wc = 0, bc = 0;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            auto m = count(it, adj, isvis);
            wc += m.first;
            bc += m.second;
        }
    }

    if (s[node - 1] == 'W')
        wc++;
    else
        bc++;
    if (wc == bc)
        fans++;
    return {wc, bc};
}
void solve()
{

    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> v(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> s;
    for (int i = 2; i <= n; i++)
    {
        adj[i].push_back(v[i]);
        adj[v[i]].push_back(i);
    }
    vector<ll> isvis(n + 1, 0);
    count(1, adj, isvis);
    cout << fans << endl;
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        fans = 0;
        solve();
    }

    return 0;
}