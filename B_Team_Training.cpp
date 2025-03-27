#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll INF = 1e18;

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());

    int teams = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;

        if (v[i] * count >= x)
        {
            teams++;
            count = 0;
        }
    }
    cout << teams << "\n";
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
