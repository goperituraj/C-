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
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n + 1, 10000000);

        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            ll a = min(x, y);
            ll b = max(x, y);
            v[a] = min(b, v[a]);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            v[i] = min(v[i], v[i + 1]);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans + v[i] - i;
        }

        cout << ans << "\n";
    }
}