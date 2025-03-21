// Read the question correctly with proper dry run of given test cases
// Visulaize the problem
// then get the solution and then code
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[i] = {x, i + 1};
        }
        sort(v.begin(), v.end());
        ll sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += v[i].first;
        }
        ll sum2 = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            sum2 += v[i].first;
        }

        vector<ll> ans;
        if (sum2 == v[n - 2].first)
        {
            ans.push_back(v[n - 1].second);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (sum - v[i].first == v[n - 1].first)
            {
                ans.push_back(v[i].second);
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}