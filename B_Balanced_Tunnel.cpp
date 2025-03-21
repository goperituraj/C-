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
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ll cnt = 0;
    map<ll, ll> mp1;
    map<ll, ll> mp2;
    for (int i = 0; i < n; i++)
    {
        mp1[a[i]] = i;
        mp2[b[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp2[a[i]] > mp1[a[i]])
        {
            cnt++;
        }
        else if (mp2[a[i]] == mp1[a[i]] && cnt > 0)
        {
            cnt++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i])
    }

    cout << cnt << endl;
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