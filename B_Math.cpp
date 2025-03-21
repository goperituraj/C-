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
map<ll, ll> factors(ll n)
{
    // vector<ll>factors;
    map<ll, ll> mp;
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
    {
        mp[n]++;
    }
    return mp;
}
void solve()
{

    ll n;
    cin >> n;
    map<ll, ll> fac = factors(n);
    ll num = 1;
    ll mx = 0;
    for (auto it : fac)
    {
        num *= it.first;
        mx = max(it.second, mx);
    }
    bool f = true;
    for (auto it : fac)
    {
        if (it.second != mx)
        {
            f = false;
        }
    }
    mx += mx % 2;
    ll k = 1;
    ll cnt = 0;
    while (k != mx)
    {
        k *= 2;
        cnt++;
    }

    if (f)
    {
        cout << num << " " << mx / 2;
    }
    else
    {
        cout << num << " " << mx / 2 + 1;
    }
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