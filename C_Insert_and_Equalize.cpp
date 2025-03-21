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
ll lcm(vector<ll> &v)
{
    ll x = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        x = (__gcd(x, v[i]));
    }
    return x;
}
void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]] = 1;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    vector<ll> diff;
    for (int i = 0; i < n - 1; i++)
    {
        diff.push_back(v[i + 1] - v[i]);
    }
    ll x = lcm(diff);
    ll ans = 0;
    ll dx = x;
    while (true)
    {
        if (mp[v[n - 1] - x] == 0)
        {
            v.push_back(v[n - 1] - x);
            break;
        }
        else
            x += dx;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        ans += (v[n] - v[i]) / dx;
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