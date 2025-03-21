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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    a[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        ll x = a[i - 1] - v[i];
        ll y = a[i - 1] + v[i];
        if (x >= 0 && y >= 0 && x != y)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            a[i] = y;
        }
    }
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
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