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
    ll idx = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
            cnt++;
        else
        {
            idx = i;
            break;
        }
    }
    ll fans = 0;
    if (cnt > 0)
        fans = 1;
    if (cnt > 3)
    {
        fans += (cnt - 1) / 3;
    }
    cnt = 0;
    // cout << idx << endl;
    for (int i = idx; i < n; i++)
    {
        if (v[i] == 1)
        {
            cnt++;
        }
        else
        {
            // cout << cnt << endl;
            fans += cnt / 3;
            cnt = 0;
        }
    }
    fans += cnt / 3;
    cnt = 0;
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