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
        ll n, p;
        cin >> n >> p;
        vector<ll> v(n);
        vector<ll> ps(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ps[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + v[i];
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool f = true;
            ll k = (p - ps[i]) / (i + 1);
            if (k < 0)
            {
                f = false;
                k = 0;
            }
            cnt += k;
            if (f)
                cnt++;
        }
        cout << cnt << endl;
    }
}