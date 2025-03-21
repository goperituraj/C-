#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    map<ll, ll> a;
    map<ll, ll> b;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        b[x]++;
    }

    ll cnt1 = k / 2;
    ll cnt2 = k / 2;
    ll in = 0;

    for (int i = 1; i <= k; i++)
    {
        if (a.find(i) != a.end() && b.find(i) != b.end())
        {
            in++;
        }
        else if (a.find(i) != a.end())
        {
            cnt1--;
            if (cnt1 < 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (b.find(i) != b.end())
        {
            cnt2--;
            if (cnt2 < 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (in == (cnt1 + cnt2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
