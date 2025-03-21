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
    if (n == 1)
    {
        cout << 0 << " " << 1 << endl;
        return;
    }
    if (n % 2 != 0)
    {
        ll x = n / 2;
        ll y = n / 2 + 1;
        if (y % 10 == 0)
        {
            while (true)
            {
                ll cnt = 0;
                bool adjust_x = false, adjust_y = false;
                ll dy = y;
                ll dx = x;
                // Count trailing zeros in `y` and remove them
                while (y % 10 == 0)
                {
                    cnt++;
                    y /= 10;
                    adjust_y = true;
                }

                // Count trailing zeros in `x` and remove them
                // while (x % 10 == 0)
                // {
                //     cnt++;
                //     x /= 10;
                //     adjust_x = true;
                // }

                // Create the adjustment value
                ll nine = 9;
                while (cnt > 1)
                {
                    nine = nine * 10 + 9;
                    cnt--;
                }
                ll adjustment = nine / 2;
                x = dx;
                y = dy;
                // Adjust x and y based on trailing zeros
                y += adjustment;
                x -= adjustment;
                swap(x, y);
                // Break condition: both x and y have no trailing zeros
                if (x % 10 != 0 && y % 10 != 0)
                {
                    cout << x << " " << y << endl;
                    return;
                }
            }
        }
        else
        {
            cout << x << " " << y << endl;
            return;
        }
    }
    else
    {
        // For even `n`, divide equally
        cout << n / 2 << " " << n / 2 << endl;
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
