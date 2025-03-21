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
        map<char, ll> mp;
        for (int i = 0; i < 26; i++)
        {
            mp['a' + i] = 0;
        }
        string s = "";
        for (int i = 0; i < n; i++)
        {
            for (auto it : mp)
            {
                if (it.second == v[i])
                {
                    s += it.first;
                    mp[it.first]++;
                    break;
                }
            }
                }
        cout << s << endl;
    }
}