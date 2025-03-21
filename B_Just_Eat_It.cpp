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
    ll osum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        osum += v[i];
    }

    ll mx = 0;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += v[i];
        mx = max(sum, mx);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    ll mx2 = 0;
    ll sum2 = 0;
    for (int i = 1; i < n; i++)
    {
        sum2 += v[i];
        mx2 = max(sum2, mx2);
        if (sum2 < 0)
        {
            sum2 = 0;
        }
    }
    mx = max(mx, mx2);
    if (mx >= osum)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
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