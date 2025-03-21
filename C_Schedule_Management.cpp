#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool check(vector<ll> &p, ll mid)
{
    ll sum = 0;
    for (int i = 1; i < p.size(); i++)
    {
        if (mid - p[i] >= 0)
        {
            sum += (mid - p[i]) / 2;
        }
        else
            sum += mid - p[i];
    }
    return sum >= 0;
}
void solve()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    vector<ll> p(n + 1);
    for (int i = 0; i < m; i++)
    {
        p[v[i]]++;
    }
    sort(p.begin(), p.end());
    ll low = 1;
    ll high = p[n];
    ll ans;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(p, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
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