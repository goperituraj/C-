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
// bool check(ll mid, vector<ll> &ps, ll k)
// {

// }
void solve()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> ps(n);
    ps[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        ps[i] = ps[i - 1] + v[i];
    }
    ll fans = 0;
    for (int i = 1; i < n; i++)
    {
        ll low = 0, high = 1e17;
        ll ans = 0;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (v[i] * 100 <= k * (ps[i - 1] + mid))
            {
                ans = mid;

                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        fans = max(ans, fans);
    }
    cout << fans << endl;
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