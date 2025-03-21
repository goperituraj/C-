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
        vector<ll> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        sort(ans.rbegin(), ans.rend());
        vector<ll> dup = ans;
        ll cnt = 0;
        ll a = ans.size();
        ll sum = 0;
        for (int i = 0; i < a; i++)
        {
            sum += ans[i];
        }
        ll alice;
        if (sum % 2 != 0)
        {
            alice = sum / 2 + 1;
        }
        else
            alice = sum / 2;
        ll bob = sum / 2;
        ll m = 0;
        for (int i = 0; i < a; i++)
        {
            m += ans[i];
            ans[i] = 0;
            while (m > bob)
            {
                m--;
                ans[i]++;
            }
            if (m == bob)
                break;
        }

        for (int i = 0; i < a; i++)
        {
            if (ans[i] == 0)
                continue;
            if (dup[i] == ans[i])
            {
                cnt += 2;
            }
            else
                cnt++;
        }
        cout << cnt << endl;
    }
}