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
    for (ll i = 0; i < n - 1; i++)
    {
        ll mn = min(v[i], v[i + 1]);
        v[i] -= mn;
        v[i + 1] -= mn;
    }
    bool ans = true;
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i + 1] < v[i])
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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