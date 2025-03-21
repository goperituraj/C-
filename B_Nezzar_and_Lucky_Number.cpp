#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;

void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (ll i = 0; i < n; i++)
    {
        ll rem = v[i] % d;
        if (rem == 0)
        {
            cout << "yes" << endl;
            continue;
        }
        ll m = d - rem;
        bool found = false;
        for (ll j = 0; j <= 10; j++)
        {
            if (d * j > v[i])
                break;
            if ((d * j) % 10 == m)
            {
                cout << "yes" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "no" << endl;
        }
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
