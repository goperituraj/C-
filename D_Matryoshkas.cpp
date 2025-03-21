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
        vector<ll> v(n);
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        // sort(v.begin(), v.end());
        vector<pair<ll, ll>> vp;
        for (auto it : mp)
        {
            vp.push_back({it.first, it.second});
        }
        ll cnt = vp[0].second;
        for (int i = 1; i < vp.size(); i++)
        {
            if (vp[i].first - vp[i - 1].first == 1)
            {
                cnt += max((ll)(0), vp[i].second - vp[i - 1].second);
            }
            else
            {
                cnt += vp[i].second;
            }
        }
        cout << cnt << endl;
    }
}