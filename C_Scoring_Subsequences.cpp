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
ll fac(ll n)
{
    ll ans = 1;
    while (n > 0)
    {
        ans *= n;
        n--;
    }
    return ans;
}
void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> res;
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        int l = 0, r = i;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] >= i - m + 1)
            {
                r = m - 1;
                ans = i - m + 1;
            }
            else
            {
                l = m + 1;
            }
        }
        res.push_back(ans);
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
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