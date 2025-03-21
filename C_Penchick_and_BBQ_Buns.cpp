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
    if (n % 2 && n < 27)
    {
        cout << -1 << endl;
    }
    else if (n % 2 && n >= 27)
    {
        cout << 1 << " " << 2 << " ";
        for (int i = 3; i < 17; i += 2)
        {

            cout << i / 2 + 2 << " " << i / 2 + 2 << " ";
        }
        cout << 1 << " ";
        for (int i = 18; i < 26; i += 2)
        {
            cout << i / 2 + 1 << " " << i / 2 + 1 << " ";
        }
        cout << 1 << " " << 2 << " ";
        for (int i = 27; i < n; i += 2)
        {
            cout << i / 2 + 1 << " " << i / 2 + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            cout << i + 1 << " " << i + 1 << " ";
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