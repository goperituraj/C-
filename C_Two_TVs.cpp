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
bool comp(pair<ll, char> &p1, pair<ll, char> &p2)
{
    if (p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}
void solve()
{
    map<ll, ll> mp;
    ll q;
    cin >> q;
    vector<pair<ll, char>> vp;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        vp.push_back({l, 's'});
        vp.push_back({r, 'e'});
    }
    sort(vp.begin(), vp.end(), comp);
    ll cnt = 0;
    for (int i = 0; i < vp.size(); i++)
    {
        if (vp[i].second == 's')
            cnt++;
        else
            cnt--;
        if (cnt > 2)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
