#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

struct DSU
{
    vector<ll> parent, rank;

    DSU(ll n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (ll i = 0; i < n; i++)
            parent[i] = i;
    }

    ll find(ll x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void join(ll x, ll y)
    {
        ll rootX = find(x), rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                swap(rootX, rootY);
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY])
                rank[rootY]++;
        }
    }

    bool connected(ll x, ll y)
    {
        return find(x) == find(y);
    }
    ll count_components(ll n)
    {
        unordered_set<ll> unique_roots;
        for (ll i = 0; i < n; i++)
        {
            unique_roots.insert(find(i));
        }
        return unique_roots.size();
    }
};

void solve()
{
    ll n;
    cin >> n;
    DSU uf1(n), uf2(n);

    ll m1, m2;
    cin >> m1 >> m2;

    vector<pair<ll, ll>> e1, e2;

    for (ll i = 0; i < m1; i++)
    {
        ll a, b;
        cin >> a >> b;
        e1.push_back({a - 1, b - 1});
    }

    for (ll i = 0; i < m2; i++)
    {
        ll a, b;
        cin >> a >> b;
        e2.push_back({a - 1, b - 1});
    }

    for (auto it : e2)
    {
        int a = it.first;
        int b = it.second;
        uf2.join(a, b);
    }

    ll ans = 0;

    for (auto it : e1)
    {
        int a = it.first;
        int b = it.second;
        if (uf2.connected(a, b))
        {
            uf1.join(a, b);
        }
        else
        {
            ans++;
        }
    }
    ll x = uf1.count_components(n);
    ll y = uf2.count_components(n);
    cout << ans + x - y << endl;
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
