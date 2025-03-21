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
    ll ans = 0;
    ll power = 1;

    for (int i = 0; i < 32; i++)
    {
        if (k & (1 << i))
        {
            ans = (ans + power) % MOD;
        }
        power = (power * n) % MOD;
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
