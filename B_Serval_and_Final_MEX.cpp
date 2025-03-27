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
    ll z = 0;
    vector<ll> idx;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
        {
            z++;
        }
    }

    if (z == 0)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else
    {
    }
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