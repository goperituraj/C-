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
            // mp[i + 1] = v[i];
        }
        ll num = v[0];
        // vector<ll> same;
        set<ll> same;
        for (int i = 1; i < n; i++)
        {
            if (v[i] == num)
                same.insert(i + 1);
        }
        vector<ll> diff;
        for (int i = 1; i < n; i++)
        {
            if (v[i] != num)
                diff.push_back(i + 1);
        }
        if (diff.size() == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            for (int i = 2; i <= n; i++)
            {
                if (same.find(i) == same.end())
                {
                    cout << 1 << " " << i << endl;
                }
            }
            for (auto it : same)
            {
                // ll x = same.top();
                cout << diff[0] << " " << it << endl;
            }
        }
    }
}