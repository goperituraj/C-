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
    ll low = 1;
    ll high = INF;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll i = 0, j = 0;
        ll sum = 0;
        ll cnt = 0;
        bool f = true;
        while (j < n)
        {
            if (v[j] > mid)
            {
                f = false;
                break;
            }
            if (sum + v[j] <= mid)
            {
                sum += v[j];
                j++;
            }
            else
            {
                cnt++;
                sum = 0;
            }
        }
        if (sum > 0)
            cnt++;
        if (cnt > k || !f)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = mid;
        }
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