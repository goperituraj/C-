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
    vector<ll> v(2 * n);
    priority_queue<ll> pq;
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        pq.push(v[i]);
    }

    sort(v.rbegin(), v.rend());
    ll e = 0, o = 0;
    vector<ll> ans(2 * n, 0);

    for (int i = 0; i < 2 * n; i += 2)
    {
        ans[i] = pq.top();
        pq.pop();
        e += ans[i];
    }

    for (ll i = 1; i < 2 * n; i += 2)
    {
        ans[i] = pq.top();
        pq.pop();
        o += ans[i];
    }

    if (e - o > v[0])
    {
        cout << e - o << " ";
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
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
