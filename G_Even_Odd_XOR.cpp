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
    ll k = n - 2;
    vector<ll> v;
    v.push_back(-1);
    for (int i = 1; i <= k; i++)
    {
        v.push_back(i);
    }

    ll a = 0, b = 0;
    for (int i = 1; i < v.size(); i += 2)
        a ^= v[i];
    for (int i = 2; i < v.size(); i += 2)
        b ^= v[i];

    while (a == b)
    {
        ll x = v.back();
        v.pop_back();
        x++;
        v.push_back(x);
        a = 0, b = 0;
        for (int i = 1; i < v.size(); i += 2)
            a ^= v[i];
        for (int i = 2; i < v.size(); i += 2)
            b ^= v[i];
    }

    ll x = a | (1LL << 30);
    ll y = b | (1LL << 30);

    if (n % 2)
    {
        v.push_back(x);
        v.push_back(y);
    }
    else
    {
        v.push_back(y);
        v.push_back(x);
    }

    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
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
