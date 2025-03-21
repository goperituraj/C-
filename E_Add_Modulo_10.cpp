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
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 10 == 5)
        {
            v[i] += 5;
        }
        if (v[i] % 10 == 0)
        {
            f = true;
        }
    }
    if (f)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] != v[i + 1])
            {
                cout << "no" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 10 == 0)
            continue;
        while (v[i] % 10 != 2)
        {
            v[i] = v[i] % 10 + v[i];
        }
    }
    for (int i = 1; i < n; i++)
    {

        if (abs(v[i] - v[i - 1]) % 20 != 0)
        {
            cout << "no" << endl;
            return;
        }
    }
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