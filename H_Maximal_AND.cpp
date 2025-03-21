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

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] & (1 << i))
            {
                cnt++;
            }
        }
        int kreqd = n - cnt;
        if (k >= kreqd)
        {
            k -= kreqd;
            ans += 1 << i;
        }
    }
    cout << ans << endl;
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