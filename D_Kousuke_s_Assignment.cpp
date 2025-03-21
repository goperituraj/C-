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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll sum = 0;
        map<ll, ll> mp;
        ll cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (v[i] == 0)
            {
                cnt++;
                sum = 0;
                mp.clear();
                mp[0] = 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                sum = 0;
                cnt++;
                mp.clear();
                mp[0] = 1;
            }
            else
                mp[sum]++;
        }
        cout << cnt << endl;
    }
}