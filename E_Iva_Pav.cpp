// Step-by-step guide:
// 1. Read the problem statement carefully.
// 2. Visualize and dry-run examples.
// 3. Implement the solution here.
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
    vector<vector<ll>> pre(n, vector<ll>(31, 0));
    for (int i = 0; i < 31; i++)
    {
        if (v[0] & 1 << i)
        {
            pre[0][i] = 1;
        }
        else
            pre[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (v[i] & 1 << j)
            {
                pre[i][j] = pre[i - 1][j] + 1;
            }
            else
                pre[i][j] = pre[i - 1][j];
        }
    }

    ll q;
    cin >> q;
    vector<ll> f;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;
        l--;

        if (v[l] < k)
        {
            f.push_back(-1);
        }
        else
        {
            ll low = l;
            ll high = n - 1;
            ll ans = -1;
            while (low <= high)
            {
                ll mid = (low + high) / 2;
                ll sum = 0;
                for (int j = 0; j < 31; j++)
                {
                    ll prev = (l > 0) ? pre[l - 1][j] : 0;
                    if (pre[mid][j] - prev == mid - l + 1)
                    {
                        sum += (1 << j);
                    }
                }
                if (sum >= k)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            f.push_back(ans);
        }
    }
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] != -1)
            cout << f[i] + 1 << " ";
        else
            cout << f[i] << " ";
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