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
        vector<ll> x(n);
        vector<ll> y(n);
        vector<ll> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        ll idx = -1;
        for (int i = 0; i < n; i++)
        {
            d[i] = y[i] - x[i];
        }
        sort(d.begin(), d.end());
        for (int i = 0; i < n; i++)
        {
            if (d[i] >= 0 && idx == -1)
                idx = i;
        }

        if (idx == -1)
        {
            cout << 0 << endl;
        }
        else if (idx == 0)
        {
            cout << n / 2 << endl;
        }
        else
        {
            ll i = idx - 1;
            ll cnt = 0;
            ll sum = d[i];

            ll rem = idx;
            ll j = n - 1; // Start from the last index
            ll steps = 0; // Count steps taken by j

            for (; j >= idx; j--)
            {
                sum += d[j];
                steps++;
                if (sum >= 0)
                {
                    cnt++;
                    i--;
                    if (i >= 0)
                        sum = d[i];
                    else
                    {
                        rem = j;
                        break;
                    }
                    steps = 0; // Reset step counter as sum is positive now
                }
            }

            // Check if j has traveled at least 2 numbers and sum is still negative
            if (steps >= 2)
            {
                cnt++; // Additional handling if needed
            }

            // if (sum > d[i])
            //     cnt++;
            if (rem >= idx)
                cnt += (rem - idx) / 2;
            cout << cnt << endl;
        }
    }
}
