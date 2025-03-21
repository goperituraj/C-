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

    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    vector<ll> t(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<ll> ans;
    ll mn = v[0];
    for (int i = 0; i < m; i++)
    {
        mn = min(mn, t[i] - v[0]);
    }
    ans.push_back(mn);
    for (int i = 1; i < n; i++)
    {
        ll low = 0;
        ll high = m - 1, fans = 1e17;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (t[mid] - v[i] >= ans.back())
            {
                high = mid - 1;
                fans = t[mid] - v[i];
            }
            else
                low = mid + 1;
        }
        if (v[i] >= ans.back())
        {
            fans = v[i];
        }
        if (fans == 1e17)
        {
            cout << "no" << endl;
            return;
        }
        ans.push_back(fans);
    }
    for (int i = 0; i < n - 1; i++)
    {

        if (ans[i] > ans[i + 1])
        {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
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