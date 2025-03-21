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
bool comp(vector<ll> &v1, vector<ll> &v2)
{
    if (v1[0] == v2[0])
    {
        return v1[1] > v2[1];
    }
    return v1[0] < v2[0];
}
void solve()
{

    ll n;
    cin >> n;
    vector<vector<ll>> vp;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y, i + 1});
    }
    sort(vp.begin(), vp.end(), comp);
    ll low = vp[0][0];
    ll high = vp[0][1];
    ll idx = vp[0][2];
    for (int i = 1; i < n; i++)
    {
        if (vp[i][1] <= high)
        {
            cout << vp[i][2] << " " << idx << endl;
            return;
        }
        else
        {
            low = vp[i][0];
            high = vp[i][1];
            idx = vp[i][2];
        }
    }
    cout << -1 << " " << -1;
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}