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

    ll n, a, b;
    cin >> n >> a >> b;
    string s, t;
    cin >> s >> t;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            v.push_back(i);
        }
    }
    if (v.size() % 2)
    {
        cout << -1 << endl;
    }
    else
    {
        if (a >= b)
        {
            if (v.size() == 0)
                cout << 0 << endl;
            else if (v.size() > 2)
            {
                cout << v.size() / 2 * b << endl;
            }
            else
            {
                if (v[1] - v[0] == 1)
                {
                    cout << min(2 * b, a) << endl;
                }
                else
                {
                    cout << b << endl;
                }
            }
        }
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