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
    ll ans = 0;
    if (n % 3 == 0)
    {
        ans += n / 3;
        if (ans % 2 == 0)
        {
            ll k = ans;
            k = ans * 3;
            ans += k / 2;
            ans += k / 2;
        }
        else
        {
            ll k = ans;
            k = ans * 3;
            ans += k / 2 + 1;
            ans += k / 2;
        }
    }
    else if (n % 3 == 1)
    {
        ans += n / 3 + 1;
        ll k = n;
        if (k == 1)
        {
            ans++;
        }
        else if (k % 2 == 0)
        {
            ans += (k / 2) - 1;
            ans += k / 2;
        }
        else
        {
            ans += k / 2;
            ans += k / 2;
        }
    }
    else
    {
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