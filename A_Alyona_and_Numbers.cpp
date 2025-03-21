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

    ll n, m;
    cin >> n >> m;
    ll one = min(n, m);
    ll two = max(n, m);
    ll cnt = 0;
    for (int i = 1; i <= one; i += 5)
    {
        cnt += ((two - 1) / 5) * 4;
        cnt += 2;
    }
    cout << cnt << endl;
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