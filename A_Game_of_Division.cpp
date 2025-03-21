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
    for (int i = 0; i < n; i++)
    {
        ll first = v[i];
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            ll diff = abs(v[j] - v[i]);
            if (diff % k == 0)
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << "yes" << endl;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "no" << endl;
    return;
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