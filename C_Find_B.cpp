// Read the question correctly with proper dry run of given test cases
// Visulaize the problem
// then get the solution and then code
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        vector<ll> c(n + 1);
        ll cnt = 0;
        c[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 1)
                cnt++;
            c[i] = cnt;
        }
        vector<ll> ps(n + 1);
        ps[0] = 0;
        ps[1] = v[1];
        for (int i = 2; i <= n; i++)
        {
            ps[i] = ps[i - 1] + v[i];
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            if (l == r)
            {
                cout << "NO" << endl;
                continue;
            }
            ll nofones = c[r] - c[l - 1];

            ll sum = ps[r] - ps[l - 1];
            sum -= nofones;
            sum -= nofones;
            if (sum >= (r - l + 1 - nofones))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}