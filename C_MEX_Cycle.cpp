#include <bits/stdc++.h>
using namespace std;

#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1, -1);

    int cur = x;
    int val = 1;

    for (int i = 0; i < n; ++i)
    {
        ans[cur] = val;
        val = 1 - val;
        cur = (cur % n) + 1;
    }

    if (n % 2 || (x - y) % 2 == 0)
        ans[x] = 2;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    fastio();
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
