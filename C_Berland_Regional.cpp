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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<vector<ll>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        v[a[i]].push_back(b[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].rbegin(), v[i].rend());
    }

    vector<vector<ll>> prefixSum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int groupSize = v[i].size();
        prefixSum[i].resize(groupSize + 1, 0);
        for (int j = 1; j <= groupSize; j++)
        {
            prefixSum[i][j] = prefixSum[i][j - 1] + v[i][j - 1];
        }
    }

    vector<ll> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int groupSize = v[i].size();
        for (int k = 1; k <= groupSize; k++)
        {
            int usableSize = (groupSize / k) * k;
            ans[k] += prefixSum[i][usableSize];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        cout << ans[k] << " ";
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