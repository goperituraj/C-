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
    ll cnt = 0;
    ll cnt2 = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2 != 0)
            cnt++;
        else
            cnt2++;
    }
    if (n == 1)
    {
        if (v[0] % 2 == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return;
    }
    if (n - cnt > 0)
    {
        cout << cnt + 1 << endl;
    }
    else
        cout << cnt - 1 << endl;
    ;
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