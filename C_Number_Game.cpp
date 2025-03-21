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

    sort(v.begin(), v.end());

    for (int k = n; k >= 0; k--)
    {
        multiset<ll> s(v.begin(), v.end());
        bool possible = true;

        for (int i = 0; i < k; ++i)
        {
            auto it = s.upper_bound(k - i);
            if (it == s.begin())
            {
                possible = false;
                break;
            }
            --it;
            s.erase(it);
            if (!s.empty())
            {
                ll x = *s.begin();
                s.erase(s.begin());
                s.insert(x + k - i);
            }
        }

        if (possible)
        {
            cout << k << endl;
            return;
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
