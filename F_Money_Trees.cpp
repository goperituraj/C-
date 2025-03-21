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
    vector<ll> a(n);
    vector<ll> h(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    ll j = 0, i = 0;
    // n = h.size() - 1;
    ll sum = 0;
    ll cnt = 0;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            f = false;
        }
    }
    if (f)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    while (j < n)
    {

        if (j == 0 || h[j - 1] % h[j] == 0)
        {
            sum += a[j];
        }
        else
        {
            i = j;
            sum = a[i];
        }
        while (sum > k)
        {
            sum -= a[i];
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
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