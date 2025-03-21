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
    ll sum = 0;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += v[i];
        }
        else
        {
            sum -= v[i];
        }

        if (mp.find(sum) != mp.end() || sum == 0)
        {
            cout << "yes" << endl;
            return;
        }
        mp[sum]++;
    }
    cout << pow(2, 31) << endl;
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