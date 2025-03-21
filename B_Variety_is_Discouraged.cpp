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
    ll cnt = 0;
    ll mx = 0;
    ll s = -1, e = -1;
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] == 1)
        {
            cnt++;
        }
        else
        {
            if (cnt > mx)
            {
                mx = cnt;
                e = i;
            }
            cnt = 0;
        }
    }
    if (cnt > 0)
    {
        if (cnt > mx)
        {
            mx = cnt;
            e = n;
        }
    }
    if (e == -1)
    {
        cout << 0 << endl;
    }
    else
        cout << e - mx + 1 << " " << e << endl;
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