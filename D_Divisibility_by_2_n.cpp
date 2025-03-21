#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            while (v[i] % 2 == 0)
            {
                v[i] /= 2;
                cnt++;
            }
        }
        vector<ll> p(n);
        for (int i = 1; i <= n; i++)
        {
            ll m = 0, j = i;
            while (j % 2 == 0)
            {
                j /= 2;
                m++;
            }
            p[i - 1] = m;
        }
        sort(p.rbegin(), p.rend());
        ll rem = n - cnt;
        if (cnt >= n)
        {
            cout << 0 << endl;
            continue;
        }

        ll steps = 0;
        for (int i = 0; i < n; i++)
        {
            rem -= p[i];
            steps++;
            if (rem <= 0)
                break;
        }

        if (rem > 0)
            cout << -1 << endl;
        else
            cout << steps << endl;
    }

    return 0;
}
