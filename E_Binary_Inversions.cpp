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
        cin >> v[i];

    vector<ll> v_copy = v;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            v[i] = 1;
            break;
        }
    }

    vector<ll> o(n, 0);
    if (v[0] == 1)
        o[0] = 1;

    for (int i = 1; i < n; i++)
    {
        o[i] = o[i - 1] + (v[i] == 1 ? 1 : 0);
    }

    ll cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            cnt1 += o[i];
    }

    v = v_copy;

    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == 1)
        {
            v[i] = 0;
            break;
        }
    }

    vector<ll> o1(n, 0);
    if (v[0] == 1)
        o1[0] = 1;

    for (int i = 1; i < n; i++)
    {
        o1[i] = o1[i - 1] + (v[i] == 1 ? 1 : 0);
    }

    ll cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            cnt2 += o1[i];
    }
    v = v_copy;

    vector<ll> o2(n, 0);
    if (v[0] == 1)
        o2[0] = 1;

    for (int i = 1; i < n; i++)
    {
        o2[i] = o2[i - 1] + (v[i] == 1 ? 1 : 0);
    }

    ll cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            cnt3 += o2[i];
    }
    cout << max({cnt1, cnt2, cnt3}) << endl;
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
