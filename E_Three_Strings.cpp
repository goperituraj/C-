#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e3 + 2;

int dp[INF][INF];

int f(int i, int j, string &a, string &b, string &c)
{
    int n = a.length();
    int m = b.length();
    int k = i + j;

    if (k == n + m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int res = 1e9;
    if (i < n && c[k] == a[i])
    {
        res = min(res, f(i + 1, j, a, b, c));
    }
    else if (i < n)
    {
        res = min(res, 1 + f(i + 1, j, a, b, c));
    }

    if (j < m && c[k] == b[j])
    {
        res = min(res, f(i, j + 1, a, b, c));
    }
    else if (j < m)
    {
        res = min(res, 1 + f(i, j + 1, a, b, c));
    }

    return dp[i][j] = res;
}

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;

    memset(dp, -1, sizeof(dp));

    cout << f(0, 0, a, b, c) << '\n';
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
