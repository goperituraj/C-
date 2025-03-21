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
    vector<ll> v(n, -1);
    v[0] = 1;
    v[1] = 1;
    v[n - 1] = 2;
    v[n - 2] = 1;
    for (int i = 2; i < n; i++)
    {
        if (v[i] == -1)
        {
            v[i] = i;
        }
    }
    for (auto it : v)
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