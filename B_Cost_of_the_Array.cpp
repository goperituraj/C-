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

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll o = 0;

    ll rem = n - o;
    if (n == k)
    {
        vector<ll> b;
        b.push_back(0);
        for (int i = 1; i < n; i += 2)
        {
            b.push_back(v[i]);
        }
        b.push_back(0);

        for (int i = 0; i < b.size(); i++)
        {
            if (i != b[i])
            {
                cout << i << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (v[i] == 1)
            o++;
    }
    if (o == n - k + 1)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 1 << endl;
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