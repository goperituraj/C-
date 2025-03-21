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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    sort(v.begin(), v.end());
    vector<ll> ans(n);

    ll mid = n / 2;
    ll i = 0, j = mid;
    for (ll k = 0; k < n; k++)
    {
        if (k % 2 == 0)
        {
            ans[k] = v[i++];
        }
        else
        {
            ans[k] = v[j++];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (!((ans[i] > ans[(i + 1) % n] && ans[i] > ans[(i + n - 1) % n]) ||
              (ans[i] < ans[(i + 1) % n] && ans[i] < ans[(i + n - 1) % n])))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
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
