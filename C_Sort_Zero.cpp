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
bool check(vector<ll> &v)
{
    ll n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}
void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    mp[v[n - 1]]--;
    if (mp[v[n - 1]] == 0)
    {
        mp.erase(v[n - 1]);
    }
    if (check(v))
    {
        cout << 0 << endl;
        return;
    }
    ll cnt = 0;
    ll idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            idx = i;
            break;
        }
    }

    for (int i = idx; i >= 0; i--)
    {

        if ((i < n - 1 && v[i] > v[i + 1]))
        {
            cnt = mp.size();
            break;
        }
        mp[v[i]]--;
        if (mp[v[i]] == 0)
            mp.erase(v[i]);
        if (mp.find(v[i]) != mp.end())
        {
            cnt = mp.size();
            break;
        }
    }
    cout << cnt << endl;
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