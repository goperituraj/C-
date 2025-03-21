#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll b, c, d;
    cin >> b >> c >> d;

    vector<ll> vd(64, 0), va(64, 0), vb(64, 0), vc(64, 0);

    for (int i = 0; i < 64; i++)
    {
        if (d & ((ll)1 << i))
            vd[i] = 1;
        if (b & ((ll)1 << i))
            vb[i] = 1;
        if (c & ((ll)1 << i))
            vc[i] = 1;
    }

    for (int i = 63; i >= 0; i--)
    {
        if (vb[i] == 1 && vc[i] == 0)
        {
            if (vd[i] != 1)
            {
                cout << -1 << endl;
                return;
            }
            va[i] = 0;
        }
        else if (vb[i] == 0 && vc[i] == 1)
        {
            if (vd[i] != 0)
            {
                cout << -1 << endl;
                return;
            }
            va[i] = 0;
        }
        else if (vb[i] == 0 && vc[i] == 0)
        {
            va[i] = (vd[i] == 0) ? 0 : 1;
        }
        else if (vb[i] == 1 && vc[i] == 1)
        {
            va[i] = (vd[i] == 0) ? 1 : 0;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 64; i++)
    {
        if (va[i])
            ans += ((ll)1 << i);
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
