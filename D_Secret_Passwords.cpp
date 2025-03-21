#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void dfs(int node, vector<vector<int>> &adj, vector<int> &isvis)
{
    isvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it])
        {
            dfs(it, adj, isvis);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> adj(26);
    vector<int> used(26, 0);

    for (auto &it : v)
    {
        if (it.length() == 1)
        {
            used[it[0] - 'a'] = 1;
            continue;
        }

        set<ll> st;
        for (char ch : it)
        {
            st.insert(ch - 'a');
            used[ch - 'a'] = 1;
        }

        vector<ll> temp(st.begin(), st.end());
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = i + 1; j < temp.size(); j++)
            {
                adj[temp[i]].push_back(temp[j]);
                adj[temp[j]].push_back(temp[i]);
            }
        }
    }

    vector<int> isvis(26, 0);
    ll cnt = 0;

    for (int i = 0; i < 26; i++)
    {
        if (used[i] && !isvis[i])
        {
            cnt++;
            dfs(i, adj, isvis);
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
