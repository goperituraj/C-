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
        vector<vector<ll>> v(n, vector<ll>(2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<pair<ll, ll>> mn;
        for (int i = 0; i < n; i++)
        {
            ll k = min(v[i][0], v[i][1]);
            mn.push_back({k, i});
        }
        sort(mn.begin(), mn.end());
        map<ll, ll> mp1;
        for (int i = 0; i < n; i++)
        {
            mp1[mn[i].first] = mn[i].second;
        }

        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            ll idx = mn[i].second;
            ans.push_back(v[idx][0]);
            ans.push_back(v[idx][1]);
        }
        vector<pair<ll, ll>> mx;
        for (int i = 0; i < n; i++)
        {
            ll k = max(v[i][0], v[i][1]);
            mx.push_back({k, i});
        }
        sort(mx.begin(), mx.end());
        map<ll, ll> mp2;
        for (int i = 0; i < n; i++)
        {
            mp2[mx[i].first] = mx[i].second;
        }
        ll sum = 0;
        for (auto it : mp1)
        {
            ll k = mp2[it.first] - mp1[it.first];
        }
        vector<ll> ans1;

        for (int i = 0; i < 2 * n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}