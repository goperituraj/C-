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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<ll> c;
    for (auto it : mp)
    {
        c.push_back(it.second);
    }
    sort(c.begin(), c.end());
    vector<ll> s(c.size(), 0);
    ll n1 = c.size();
    if (n1 == 1)
    {
        cout << 0 << endl;
        return;
    }
    s[n1 - 1] = c[n1 - 1];
    for (int i = n1 - 2; i >= 0; i--)
    {
        s[i] = s[i + 1] + c[i];
    }
    vector<ll> p(n1, 0);
    p[0] = c[0];
    for (int i = 1; i < n1; i++)
    {
        p[i] = p[i - 1] + c[i];
    }
    ll ans = 1e15;
    for (int i = 0; i < n1; i++)
    {
        ll l = n1 - i - 1;
        if (i == 0)
        {
            ans = min(ans, s[i + 1] - l * c[i]);
        }
        else if (i == n1 - 1)
        {
            ans = min(ans, p[i - 1]);
        }
        else
            ans = min(ans, p[i - 1] + s[i + 1] - l * c[i]);
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