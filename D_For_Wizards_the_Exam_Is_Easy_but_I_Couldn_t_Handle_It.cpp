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
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        ll cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
                cnt--;
            else if (v[j] > v[i])
                cnt++;

            if (cnt < ans)
            {
                ans = cnt;
                l = i;
                r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << " " << endl;
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