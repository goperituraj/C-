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
bool issorted(vector<ll> v)
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

    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "yes" << endl;
        return;
    }
    vector<ll> ps;
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        ps.push_back(x);
    }
    vector<ll> v;
    for (int i = 0; i < ps.size() - 1; i++)
    {
        v.push_back(ps[i + 1] - ps[i]);
    }
    bool is = issorted(v);
    if (!is)
    {
        cout << "no" << endl;
    }
    else
    {
        ll rem = n - k + 1;
        if (v.size() >= 1 && ps[0] <= rem * v[0])
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
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