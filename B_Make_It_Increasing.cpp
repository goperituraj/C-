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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll cnt = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] >= v[i + 1])
        {

            if (v[i + 1] == 0)
            {
                cout << -1 << endl;
                return;
            }

            ll target = v[i + 1] - 1;
            while (v[i] > target)
            {
                v[i] /= 2;
                cnt++;
            }

            if (v[i] == 0 && i != 0)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << cnt << endl;
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