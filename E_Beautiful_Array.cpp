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
    cout << 3 << endl;
    ll mean = n * 3;
    mean -= k;
    if (mean >= k)
    {
        cout << 0 - 120 << " " << k << " " << mean + 120;
    }
    else
    {
        cout << mean - 120 << " " << k << " " << 0 + 120;
    }
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}