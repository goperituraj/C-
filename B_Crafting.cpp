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
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> d(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll cnt = 0;
    ll sum = 0;
    ll mn = 1e9;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] - b[i] >= 0)
            mn = min(a[i] - b[i], mn);
        if (a[i] - b[i] < 0)
        {
            sum += a[i] - b[i];

            cnt++;
        }
    }
    if (cnt > 1 || sum + mn < 0)
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