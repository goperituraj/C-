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
        ll n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        ll cnt = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt++;
                if (cnt == m)
                {
                    ans++;
                    cnt = 0;
                    i += k - 1;
                }
            }
            else
                cnt = 0;
        }
        cout << ans << endl;
    }
}