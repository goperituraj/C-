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
    vector<ll> dig;
    for (int i = 0; i < n; i++)
    {
        ll x = v[i];
        vector<int> ans;
        while (x > 0)
        {
            ans.push_back(x % 10);
            x = x / 10;
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            dig.push_back(ans[i]);
        }
    }
    vector<ll> s = dig;
    sort(s.begin(), s.end());
    if (s == dig)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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