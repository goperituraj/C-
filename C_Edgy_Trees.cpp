#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll ans = 0;
ll n, k;

ll mod_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void dfs(ll node, vector<ll> &isvis, vector<vector<pair<ll, ll>>> &adj, ll &cnt)
{
    isvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!isvis[it.first] && it.second == 0)
        {
            cnt++;
            dfs(it.first, isvis, adj, cnt);
        }
    }
}

void solve()
{
    cin >> n >> k;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<ll> isvis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!isvis[i])
        {
            ll cnt = 1;
            bool f = false;
            for (auto it : adj[i])
            {
                if (it.second == 0)
                {
                    f = true;
                    break;
                }
            }
            if (f)
            {
                dfs(i, isvis, adj, cnt);
                ans = (ans + mod_pow(cnt, k, MOD)) % MOD;
            }
        }
    }

    ll c = 0;
    for (auto it : isvis)
    {
        if (it == 1)
            c++;
    }
    ll fans = (mod_pow(n, k, MOD) - ans - n + c + MOD) % MOD;
    cout << fans << endl;
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
