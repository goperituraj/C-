#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Function to calculate the sum of the first `n` natural numbers
ll ap(ll n)
{
    return (n * (n + 1)) / 2;
}

// Function to calculate the sum in descending order like `4 + 3 + ...`
ll dp(ll n, ll m)
{
    return ap(m) - ap(n - 1); // Sum from `n` to `m`
}

void solve()
{
    ll k, x;
    cin >> k >> x;

    // If `x` is large enough to include all `2k - 1` elements
    if (x >= 2 * ap(k) - k)
    {
        cout << 2 * k - 1 << endl;
        return;
    }

    // Binary search for the ascending part
    ll low = 1, high = k, ans = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (x >= ap(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Reduce `x` by the sum of the ascending part
    x -= ap(ans);
    if (x == 0)
    {
        cout << ans << endl;
        return;
    }

    // Binary search for the descending part (4 + 3 + ... logic)
    low = 1, high = k - 1;
    ll ans2 = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (x >= dp(mid, k - 1))
        {
            ans2 = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Calculate the total number of elements needed
    cout << ans + (k - ans2) << endl;
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
