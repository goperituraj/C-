#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x;
    cin >> x;

    if ((x & (x - 1)) == 0)
    {
        cout << -1 << endl;
        return;
    }

    long long y = x + 1;

    if ((y & (y - 1)) == 0)
    {
        cout << -1 << endl;
        return;
    }

    for (long long y = 1; y <= 30000; y++)
    {
        long long a = (x ^ y);

        if ((a + y) > x && (a + x) > y && (x + y) > a)
        {
            cout << y << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}