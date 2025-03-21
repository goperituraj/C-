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

    ll n, a, b;
    cin >> n >> a >> b;
    ll diff = b - a - 1;
    if (diff == 0)
    {
        if (a == 1 && b == 2)
        {
            cout << "no" << endl;
            return;
        }
    }
    if (diff % 2 != 0)
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