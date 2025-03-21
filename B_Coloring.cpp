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

    ll n, x, k;
    cin >> n >> x >> k;
    vector<ll> v(x);
    for (ll i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    ll h = 0;
    if (n % k != 0)
    {
        h = 1;
    }
    h += n / k;
    ll cnt = 0;
    for (int i = 0; i < x; i++)
    {
        if (v[i] == h)
            cnt++;
    }

    if (v[0] > h || (n % k != 0) && cnt > (n % k))
    {
        cout << "no" << endl;
    }
    else
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