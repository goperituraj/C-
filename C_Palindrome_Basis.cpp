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
vector<ll> ps;
vector<vector<ll>> dp;

bool check(ll num)
{
    string temp = to_string(num);
    string ans = temp;
    reverse(ans.begin(), ans.end());
    return (temp == ans);
}

void pre()
{
    for (ll i = 1; i <= 40000; i++)
    {
        if (check(i))
            ps.push_back(i);
    }
}

ll f(ll idx, ll sum)
{
    if (sum == 0)
        return 1;
    if (idx >= ps.size() || sum < 0)
        return 0;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    ll take = f(idx, sum - ps[idx]);
    ll nottake = f(idx + 1, sum);

    return dp[idx][sum] = (take + nottake) % MOD;
}

void solve()
{
    ll n;
    cin >> n;

    cout << f(0, n) << endl;
}

int main()
{
    fastio();
    pre();
    int t;
    cin >> t;
    dp.assign(1000, vector<ll>(1e4 + 1, -1));
    while (t--)
    {
        solve();
    }
    return 0;
}
