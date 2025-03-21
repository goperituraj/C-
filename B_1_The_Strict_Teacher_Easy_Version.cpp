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

    ll n, m, k;
    cin >> n >> m >> k;
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    ll ans = 1e10;
    if (c < b && c > a)
    {

        ans = (b - a) / 2;
    }
    else if (c > b)
    {
        ans = c - b + n - c;
    }
    else
    {
        ans = a - c + c - 1;
    }
    cout << ans << endl;
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