#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    // if (n == 1)
    // {
    //     cout << 1 << endl;
    //     cout << 1 << endl;
    //     return;
    // }
    for (int i = 0; i < 64; i++)
    {
        if (n & (1LL << i))
        {
            v.push_back(1LL << i);
        }
    }
    if (v.size() > 1)
        cout << v.size() + 1 << endl;
    else
    {
        cout << v.size() << endl;
    }
    vector<ll> ans;

    for (ll x : v)
    {
        ans.push_back(n - x);
    }

    sort(ans.begin(), ans.end());
    for (ll x : ans)
    {
        if (x != 0)
            cout << x << " ";
    }
    cout << n;
    cout << endl;
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
