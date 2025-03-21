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

    ll a, b, l;
    cin >> a >> b >> l;
    vector<ll> factors;
    // factors.push_back(1);
    ll cnt1 = 1;
    while (l % a == 0)
    {
        cnt1++;
        l = l / a;
    }
    ll cnt3 = 0;
    if (l % b != 0)
        cnt3++;
    ll cnt2 = 1;
    while (l % b == 0)
    {
        cnt2++;
        l = l / b;
    }
    if (l % a != 0)
        cnt3++;
    while (l % a == 0)
    {
        cnt1++;
        l = l / a;
    }
    cout << cnt1 * cnt2 + cnt3 << endl;
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