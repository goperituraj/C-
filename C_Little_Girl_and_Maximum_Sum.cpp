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

    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        pre[l]++;
        pre[r + 1]--;
    }
    vector<ll> v(n);
    v.push_back(pre[0]);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i] + pre[i - 1];
        v.push_back(pre[i]);
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i] * arr[i];
    }
    cout << ans << endl;
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