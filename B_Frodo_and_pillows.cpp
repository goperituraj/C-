#include "bits/stdc++.h"

using namespace std;

#define int long long
int getsum(int a)
{
    a = abs(a);
    return (a * (1 + a)) / 2;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int lftlen = k - 1;
    int rghtlen = n - k;
    int l = 0;
    int r = m + 1;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        int lft = getsum(mid - 1) - (mid - 1 > lftlen ? getsum(mid - 1 - lftlen) : -(lftlen - mid + 1));
        int rght = getsum(mid - 1) - (mid - 1 > rghtlen ? getsum(mid - 1 - rghtlen) : -(rghtlen - mid + 1));
        if (lft + rght + mid <= m)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << max(0ll, l) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();
    return 0;
}