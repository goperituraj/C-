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
        ll n;
        cin >> n;
        vector<ll> v(n + 1);
        ll cnt = 0;
        map<ll, ll> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] = v[i] - i;
            mp[v[i]]++;
        }
        ll ans = 0;
        for (auto it : mp)
        {
            ll k = it.second;
            k--;
            ans += ((k) * (k + 1)) / 2;
        }

        cout << ans << endl;
    }
}