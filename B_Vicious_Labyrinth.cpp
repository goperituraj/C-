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
    if (k % 2 == 1)
    {

        for (int i = 1; i <= n; i++)
        {
            if (i == n)
            {
                cout << n - 1 << " ";
            }
            else
                cout << n << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == n - 1)
            {
                cout << n << " ";
            }
            else
                cout << n - 1 << " ";
        }
        cout << endl;
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