#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        vector<ll> v(n);
        ll sum = 0;
        map<ll, ll> mp1;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            if (mp1.find(sum) == mp1.end())
            {
                mp1[sum] = i + 1;
            }
        }

        ll rem = sum - s;

        if (rem == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if (rem < 0)
        {
            cout << -1 << endl;
            continue;
        }

        sum = 0;
        map<ll, ll> mp2;

        for (int i = n - 1; i >= 0; i--)
        {
            sum += v[i];
            if (mp2.find(sum) == mp2.end())
            {
                mp2[sum] = n - i;
            }
        }

        ll ans = 1e9;

        if (mp1.find(rem) != mp1.end())
        {
            ans = min(ans, mp1[rem]);
        }
        if (mp2.find(rem) != mp2.end())
        {
            ans = min(ans, mp2[rem]);
        }

        ll x = rem - 1, y = 1;
        while (x > 0)
        {
            // if (mp1.find(x) != mp1.end() && mp2.find(y) != mp2.end())
            // {
            ll k = mp1[x] + mp2[y];
            ans = min(k, ans);
            // }
            x--;
            y++;
        }
        cout << (ans == 1e9 ? -1 : ans) << endl;
    }
}
