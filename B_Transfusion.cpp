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
    bool f = true;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % n != 0)
    {
        cout << "NO" << endl;
        return;
    }
    ll k = sum / n;
    ll cnt = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != k)
        {
            sum2 += v[i];
            cnt++;
        }
    }
    if (cnt == n)
    {
        cout << "YES" << endl;
        return;
    }
    if (f)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
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