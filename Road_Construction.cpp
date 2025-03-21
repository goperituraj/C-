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
vector<ll> parent, size;
ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void unite(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if (size[x] > size[y])
    {
        parent[y] = x;
        size[x] += size[y];
    }
    else if (size[x] < size[y])
    {
        parent[x] = y;
        size[y] += size[x];
    }
    else
    {
        parent[x] = y;
        size[y] += size[x];
    }
}

void solve()
{

    ll n, k;
    cin >> n >> k;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    size.resize(n + 1, 1);
    ll com = n;
    ll ans = 0;
    while (k--)
    {
        ll a, b;
        cin >> a >> b;
        if (find(a) != find(b))
        {
            com--;
            cout << com << " ";
            unite(a, b);
            ans = max(ans, size[find(a)]);
            cout << ans << endl;
        }
        else
        {
            cout << com << " ";
            cout << ans << endl;
        }
    }
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