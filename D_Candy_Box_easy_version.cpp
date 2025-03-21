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

    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll n;
        cin >> n;
        vector<ll> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[x]++;
        }
        sort(v.rbegin(), v.rend());
        ll ans = v[0];
        ll prev = v[0];
        for (int i = 1; i < v.size() - 1; i++)
        {
            if (prev == 0)
                break;
            if (v[i] < prev)
            {
                ans += v[i];
                prev = v[i];
            }
            else
            {
                ans += prev - 1;
                prev = prev - 1;
            }
        }
        cout << ans << endl;
    }
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