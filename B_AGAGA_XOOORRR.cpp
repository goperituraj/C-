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
    vector<ll> v(n);
    ll xo = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        xo ^= v[i];
    }
    if (xo == 0)
    {
        cout << "yes" << endl;
        return;
    }
    vector<ll> pr(n);
    pr[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pr[i] = v[i] ^ pr[i - 1];
    }
    for (int i = 0; i < n - 2; i++)
    {
        ll start = pr[i];
        for (int j = i + 1; j < n; j++)
        {
            ll mid = pr[j] ^ start;
            ll end = pr[n - 1] ^ start ^ mid;
            if (start == mid && mid == end)
            {
                cout << "yes" << endl;
                return;
            }
        }
    }
    cout << "no" << endl;
    return;
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