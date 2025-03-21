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
    ll k = v[0];
    for (int i = 1; i < n; i++)
    {
        k = __gcd(v[i], k);
    }
    if (k > 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<ll> dis(n, 1e12);
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
            cnt++;
    }
    if (cnt > 0)
    {
        cout << n - cnt << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        ll k = v[i];
        for (int j = i + 1; j < n; j++)
        {
            k = __gcd(v[j], k);
            if (k == 1)
            {
                dis[i] = j - i;
                break;
            }
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (240 & 1 << i)
        {
            cout << pow(2, i) << " ";
        }
    }
    // for (auto it : dis)
    // {
    //     cout << it << " ";
    // }
    sort(dis.begin(), dis.end());
    cout << dis[0] + n - 1 << endl;
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