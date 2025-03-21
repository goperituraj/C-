#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> v(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];

        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            ll mn = 0, x = 0, y = i;
            while (x < n && y < n)
            {
                mn = min(mn, v[x][y]);
                x++, y++;
            }
            cnt += mn;
        }

        for (int i = 1; i < n; i++)
        {
            ll mn = 0, x = i, y = 0;
            while (x < n && y < n)
            {
                mn = min(mn, v[x][y]);
                x++, y++;
            }
            cnt += mn;
        }

        cout << abs(cnt) << endl;
    }
    return 0;
}
