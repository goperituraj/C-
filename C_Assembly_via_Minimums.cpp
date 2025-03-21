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
        ll k = ((n) * (n - 1)) / 2;
        vector<ll> v(k);
        map<ll, ll> mp;
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        vector<ll> ans;
        // for (auto it : mp)
        // {
        //     ans.push_back(it.second);
        // }
        // sort(ans.rbegin(), ans.rend());
        for (int i = n - 1; i >= 0; i--)
        {
            for (auto it : mp)
            {
                if (it.second >= i)
                {
                    ans.push_back(it.first);
                    mp[it.first] -= i;
                    if (mp[it.first] == 0)
                        mp.erase(it.first);
                    break;
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << 1000000000;
        cout << endl;
    }
}